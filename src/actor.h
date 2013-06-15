#ifndef TKTR_ACTOR_H_
#define TKTR_ACTOR_H_

#include <iostream>
#include <string>

#include "action.h"

namespace tktr {

	class Actor {
		public:
			void act(const Action& act, const std::string& tag) {
				std::cout << "Act [" << static_cast<int>(act) << "]"
				             " on \"" << tag << "\"" << std::endl;
			}

			struct Excpetion {};
	};

} //namespace tktr

#endif //TKTR_ACTOR_H_
