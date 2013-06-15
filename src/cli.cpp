#include <string>
#include <cstring>

#include "action.h"
#include "cli.h"

tktr::Action tktr::CLI::parse_action(const char *src)
{
	switch (src[0]) {
		case 'n':
			if (!src[1] || !strncmp(src, "new", 3))
				return tktr::Action::Create;
			break;
		case 'c':
			if (!src[1] || !strncmp(src, "complete", 8))
				return tktr::Action::Complete;
			break;
		case 's':
			if (!src[1] || !strncmp(src, "start", 5))
				return tktr::Action::Start;
			break;
		case 'p':
			if (!src[1] || !strncmp(src, "pause", 5))
				return tktr::Action::Pause;
			break;
	}

	throw std::exception();
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
			throw std::exception();
	}
}
