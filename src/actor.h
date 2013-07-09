#ifndef TKTR_ACTOR_H_
#define TKTR_ACTOR_H_

#include <iostream>
#include <string>

#include "action.h"
#include "storage.h"

namespace tktr {

	class Actor {
		public:
			Actor(const tktr::Storage& store) : store_(store) {}
			void act(const Action& act, const std::string& tag) {
				std::cout << "Act [" << static_cast<int>(act) << "]"
				             " on \"" << tag << "\"" << std::endl;

				switch(act) {
					case tktr::Action::Create:
						this->store_.save(tag); break;
					case tktr::Action::Complete:
						this->store_.drop(tag); break;
					case tktr::Action::Start:
						this->store_.load(tag);
						this->store_.save(tag);
						break;
					case tktr::Action::Pause:
						this->store_.load(tag);
						this->store_.save(tag);
						break;

					default:
						throw Exception();
				}
			}

			struct Exception {};

		private:
			Storage store_;
	};

} //namespace tktr

#endif //TKTR_ACTOR_H_
