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

	class Storage {
		public:
			Storage(const std::string& path = cfg::defaults::data_directory) : path_(path) {}
			~Storage() {}

			void save(const std::string& tag) { std::cout << "Saving to " << this->path_ << "/" << tag << std::endl; }
			void load(const std::string& tag) { std::cout << "Loading from " << this->path_ << "/" << tag << std::endl; }
			void drop(const std::string& tag) { std::cout << "Dropping " << this->path_ << "/" << tag << std::endl; }

		private:
			std::string path_;
	};
} //namespace tktr

#endif // TKTR_STORAGE_H_
