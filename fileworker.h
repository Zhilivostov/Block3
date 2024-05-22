#pragma once
#include <string>

class filehandler final {

public:
	void sort_file(const std::string&) const;

	void merge_files(const std::string&, const std::string&, const std::string&) const;

	void clear_file(const std::string&) const;

};