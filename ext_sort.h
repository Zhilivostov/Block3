#pragma once
#include <iostream>
#include "fileworker.h"

class external_sort final{
private:

	std::string filein;
	std::string fileout;
	size_t max_size;
	filehandler fwork;
	const std::string nameblock = "block";
	const std::string txt = ".txt";

public:

	external_sort(const std::string&, const std::string&, size_t);

	const void ext_merge_sort() const;
};