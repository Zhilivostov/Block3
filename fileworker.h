#pragma once
#include <string>

class filehandler final {

public:
	static void sort_file(const std::string&);

	static void merge_files(const std::string&, const std::string&, const std::string&);

	static void clear_file(const std::string&);

};
