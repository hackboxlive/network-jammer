#include <iostream>
#include "command_line.hpp"

using namespace std;

command_line::command_line()	{
	state = CHOOSEIF;
}

command_line::~command_line()	{
}

void command_line::execute()	{
	while(1)	{
		show_menu();
		usleep(100000);
	}
}

void command_line::show_menu()	{
	if(state != WHITELIST)	{
		system("clear");
	}
	show_header();
	show_action();
}

void command_line::show_header()	{
	cout << "----------------Boom--------------" << endl;
	cout << "----------------------------------" << endl;
	cout << "Kick em out of your personal space" << endl;
	cout << "**********************************" << endl;
}

void command_line::show_action()	{
	switch(state)	{
		
		case CHOOSEIF:
			list_interfaces();
			int interface_id;
			cout << endl << endl << "Interface: ";
			cin >> interface_id;
			choose_interface(interface_id);
			state = LISTAPS;
			break;
		
		case LISTAPS:
			list_accesspoints();
			int accesspoint_id;
			cout << endl << endl << "Access point: ";
			cin >> accesspoint_id;
			choose_accesspoint(accesspoint_id);
			state = LISTHOSTS;
			break;
		
		case LISTHOSTS:
			list_connectedhosts();
			state = WHITELIST;
			break;

		case WHITELIST:
			state = ATTACK;
			break;

		case ATTACK:
			attack();
			break;
	}
}

void command_line::list_interfaces()	{
	interfaces = network_obj.get_connected_devices();

	int i = 0;
	for(const wstring& iface : interfaces)	{
		wcout << ++i << ". " << iface << endl;
	}
}

void command_line::choose_interface(int id)	{
	wstring w_iface = interfaces.at(id - 1);
	using convert_type = codecvt_utf8<wchar_t>;
	wstring_convert<convert_type, wchar_t> converter;

	string iface = converter.to_bytes(w_iface);
	network_obj.set_interface(iface);
}

void command_line::list_accesspoints()	{
	aps = network_obj.get_access_points();
	cout << endl << endl;
	int i = 0;
	for(const pair<string, set<address_type> >& p: aps)	{
		if(p.first == "")	{
			aps.erase(p.first);
			continue;
		}
		cout << i++ << ". " << p.first << " -> [";
		for(set<address_type>::iterator it = p.second.begin(); it != p.second.end(); it++)	{
			cout << (*it).to_string();
			if((it != p.second.end()) && (next(it) != p.second.end()))	{
				cout << ", ";
			}
		}
		cout << "]" << endl;
	}
}

void command_line::choose_accesspoint(int id)	{
	int i = 1;
	for(map<string, set<address_type> >::iterator it = aps.begin(); it != aps.end(); it++, i++)	{
		if(i == id)	{
			network_obj.set_bssid((*(it->second.begin())).to_string());
			break;
		}
	}
}

void command_line::list_connectedhosts()	{
	targets = network_obj.get_connected_devices();
}

void command_line::attack()	{
	cout << "-> BSSID: " << network_obj.get_bssid() << endl;
	cout << "-> Target: xx:xx:xx:xx:xx:xx" << endl << endl;
	cout << "Deauthenticating.. (ctrl + c) to stop" << endl;

	while(true)	{
		network_obj.send_deauth();
		usleep(1000000);
	}
}