#ifndef TKTR_FILESTORE_H_
#define TKTR_FILESTORE_H_

#include "storage.h"

namespace tktr {
	namespace data {

		class FileStorage : public Storage {
			public:

				void save(const Record& r) { std::cout << "Saving to " << this->path_ << "/" << r.tag << std::endl; }
				void load(const Record& r) { std::cout << "Loading from " << this->path_ << "/" << r.tag << std::endl; }
				void drop(const Record& r) { std::cout << "Dropping " << this->path_ << "/" << r.tag << std::endl; }
		};

	} //namespace tktr
} //namespace tktr

#endif // TKTR_FILESTORE_H_
