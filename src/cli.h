#ifndef TKTR_CLI_H_
#define TKTR_CLI_H_

#include <string>

#include "action.h"

namespace tktr {

	class CLI {
		public:
			CLI() : tag_{}, act_{Action::Undefined} {}
			CLI(int argc, const char **argv) {}

			std::string tag() { return tag_; }
			inline Action action() { return act_; }

		private:
			std::string tag_;
			Action act_;
	};

} //namespace tktr

#endif //TKTR_CLI_H_
