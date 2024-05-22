#include "ext_sort.h"
#include <fstream>
#include <string>
#include <algorithm>
#include <set>


external_sort::external_sort(const std::string& in, const std::string& out, size_t size)
{
    if ((!in.empty()) && (!out.empty()) && (size > 0))
    {
        filein = in;
        fileout = out;
        max_size = size;
    }
    else
        throw std::invalid_argument("Invalid argument or arguments were gotten!");
}


const void external_sort::ext_merge_sort() const
{
    size_t size = max_size;
    int elem;

    std::ifstream in(filein);
    if (in.is_open() != true)
        throw std::invalid_argument("This file does not exist!");
    size_t count_blocks = 1;

    while (!in.eof())
    {
        std::ofstream block(nameblock + std::to_string(count_blocks++) + txt);
        for (size_t count_elem = 0; count_elem < max_size; count_elem++)
        {
            in >> elem;
            block << elem << " ";
            if (in.eof()) break;
        }
        block.close();
    }
    in.close();

    for (int j = 1; j < count_blocks; j++)
        fwork.sort_file(nameblock + std::to_string(j) + txt);

    size_t m = count_blocks;
    for (int k = 1; k < m; k++)
        fwork.merge_files(nameblock + std::to_string(k) + txt, nameblock + std::to_string(k + 1) + txt, nameblock + std::to_string(k + 1) + txt);
    
    std::ofstream out(fileout);
    std::ifstream last_block(nameblock + std::to_string(count_blocks - 1) + txt);
    out << last_block.rdbuf();
    last_block.clear();
    last_block.close();

    for (int j = 1; j < count_blocks; j++)
        fwork.clear_file(nameblock + std::to_string(j) + txt);
}
