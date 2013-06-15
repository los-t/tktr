#include <iostream>

#include "actor.h"
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
	try {
		tktr::CLI cli(argc, argv);
		tktr::Actor actor;
		actor.act(cli.action(), cli.tag());
	}
	catch (tktr::CLI::Exception) {
		print_usage();
		return 1;
	}
	catch (tktr::Actor::Excpetion) {
		return 1;
	}

	return 0;
}
