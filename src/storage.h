#ifndef TKTR_STORAGE_H_
#define TKTR_STORAGE_H_

#include <iostream>
#include <string>

namespace tktr {
	namespace cfg {
		namespace defaults {

		const std::string app_directory = "~/.tktr/";
		const std::string config_path = app_directory + "tktrrc";
		const std::string data_directory = app_directory + "data";

		} //namespace defaults
	} //namespace cfg

	namespace data {

		struct Record {
			uint64_t id;
			std::string tag;
		};

		class Storage {
			public:
				Storage(const std::string& path = cfg::defaults::data_directory) : path_(path) {}
				virtual ~Storage() {}

				virtual void save(const Record&) = 0;
				virtual void load(const Record&) = 0;
				virtual void drop(const Record&) = 0;

			protected:
				std::string path_;
		};
	} //namespace data
} //namespace tktr

#endif // TKTR_STORAGE_H_
