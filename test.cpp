//#include "pch.h"
#include "ext_sort.h"
#include <fstream>
#include <gtest/gtest.h>
#include <algorithm>

TEST(Test, Good_situation) {
	external_sort a("task_test.txt", "result_test.txt", 7);
	a.ext_merge_sort();
	std::ifstream in_check("result_test.txt");
	std::vector<int> vec;
	std::string item;
	while (in_check >> item)
	{
		if (!item.empty())
			vec.push_back(std::stoi(item));
		else
			in_check.close();
	}

	EXPECT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(Test, Bad_situation) {

	ASSERT_ANY_THROW(external_sort b("", "", 0));
	ASSERT_ANY_THROW(external_sort b("task.txt", "", 1));
	ASSERT_ANY_THROW(external_sort b("", "result_bad.txt", 5));
	ASSERT_ANY_THROW(external_sort b("task.txt", "result_bad.txt", 0));
}

TEST(Test, Empty_file) {
	external_sort b("task_empty.txt", "result_empty.txt", 5);
	ASSERT_NO_THROW(b.ext_merge_sort());
}

TEST(Test, NO_file) {
	external_sort b("task_empt.txt", "result_empty.txt", 5);
	ASSERT_ANY_THROW(b.ext_merge_sort());
}