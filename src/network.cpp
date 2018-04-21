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
