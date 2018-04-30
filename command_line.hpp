#ifndef COMMAND_LINE_HPP
#define COMMAND_LINE_HPP

#include <string>
#include <unistd.h>
#include <cassert>
#include <clocale>
#include <locale>
#include <vector>
#include <codecvt>
#include "network.hpp"

class command_line	{
	typedef Tins::Dot11::address_type address_type;

	enum state_	{
		CHOOSEIF,
		LISTAPS,
		LISTHOSTS,
		WHITELIST,
		ATTACK
	};

	public:
		command_line();
		virtual ~command_line();
		void execute();

	private:
		state_ state;
		network network_obj;
		std::vector<std::wstring> interfaces;
		std::map<std::string, std::set<address_type> > aps;
		std::vector<std::string> targets;

		void show_menu();
		void show_header();
		void show_action();
		void list_interfaces();
		void list_accesspoints();
		void choose_interface(int id);
		void choose_accesspoint(int id);
		void list_connectedhosts();
		void attack();
};

#endif