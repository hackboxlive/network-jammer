#ifndef NETWORK_H
#define NETWORK_H

#include <tins/tins.h>

class network	{
	typedef Tins::Dot11::address_type address_type;
	typedef std::set<address_type> ssids_type;
	
	private:
		ssids_type ssids;
		std::map<std::string, std::set<address_type> > access_points;
		std::string iface_name;
		Tins::PacketSender sender;
		Tins::HWAddress<6> bssid;
		Tins::HWAddress<6> target;
		Tins::IPv4Range network_range = Tins::IPv4Range::from_mask("10.10.10.2", "10.10.10.255");
		Tins::Dot11Deauthentication deauth_packet;
		Tins::RadioTap radio;
		bool scan_callback(Tins::PDU& pdu);
		bool scanning = true;
		static void stop_scan(bool *scanning);

	public:
		network();
		virtual ~network();
		void send_deauth();
		std::vector<std::wstring> get_interfaces();
		void set_interface(std::string interface);
		void set_bssid(const std::string hw_address);
		std::string get_bssid();
		std::vector<std::string> get_connected_devices();
		std::map<std::string, std::set<address_type> > get_access_points();

};

#endif