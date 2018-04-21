#include "../include/command_line.hpp"

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

