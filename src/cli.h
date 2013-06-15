#ifndef TKTR_CLI_H_
#define TKTR_CLI_H_

#include <string>

#include "action.h"

namespace tktr {

	class CLI {
		public:
			CLI() : tag_{}, act_{Action::Undefined} {}
			CLI(int argc, const char **argv);

			std::string tag() { return tag_; }
			Action action() { return act_; }

			struct Exception {};
		private:
			std::string tag_;
			Action act_;

			static Action parse_action(const char *src);
	};

} //namespace tktr

#endif //TKTR_CLI_H_
