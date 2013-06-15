#include <iostream>

#include "action.h"
#include "cli.h"

void print_usage(void)
{
	std::cout << "tktr - your simple task tracker" << std::endl
						<< "Usage: tktr [action] [tag]" << std::endl
						<< "Tag is the key to find your task" << std::endl
						<< "Actions:" << std::endl
						<< "\tn[ew]\t\t- create new task" << std::endl
						<< "\tc[omplete]\t- complete existing task" << std::endl
						<< "\ts[tart]\t\t- start a (possibly new) task" << std::endl
						<< "\tp[ause]\t\t- pause a running task" << std::endl;
}

int main(int argc, const char **argv)
{
	tktr::CLI cli(argc, argv);

	if (cli.action() == tktr::Action::Undefined)
		print_usage();
	else
		std::cout << "Action is [" << (int)cli.action() << "] on \"" << cli.tag() << "\"" << std::endl;


	return 0;
}
