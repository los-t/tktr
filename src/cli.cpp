#include <string>
#include <cstring>

#include "action.h"
#include "cli.h"

tktr::Action tktr::CLI::parse_action(const char *src)
{
	tktr::Action act = tktr::Action::Undefined;
	switch (src[0]) {
		case 'n':
			if (!src[1] || !strncmp(src, "new", 3))
				act = tktr::Action::Create;
			break;
		case 'c':
			if (!src[1] || !strncmp(src, "complete", 8))
				act = tktr::Action::Complete;
			break;
		case 's':
			if (!src[1] || !strncmp(src, "start", 5))
				act = tktr::Action::Start;
			break;
		case 'p':
			if (!src[1] || !strncmp(src, "pause", 5))
				act = tktr::Action::Pause;
			break;
	}

	return act;
}

tktr::CLI::CLI(int argc, const char **argv)
{
	switch (argc) {
		case 3:
			this->tag_ = std::string(argv[2]);
		case 2:
			this->act_ = CLI::parse_action(argv[1]);
			break;
		default:
			this->act_ = tktr::Action::Undefined;
	}
}
