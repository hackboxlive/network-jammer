#ifndef COMMAND_LINE_HPP
#define COMMAND_LINE_HPP

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
		
}

#endif