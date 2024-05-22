#include "fileworker.h"
#include <fstream>
#include <set>


void filehandler::sort_file(const std::string& filename) const
{
    if (!filename.empty())
    {
        std::ifstream fin(filename);
        std::multiset<int> mset;
        int elem;
        while (fin >> elem)
            mset.insert(elem);

        fin.clear();
        fin.close();

        std::ofstream fout(filename);

        for (const auto& item : mset)
            fout << item << " ";
    }
}

void filehandler::merge_files(const std::string& hard_mem, const std::string& ram, const std::string& fileout) const
{
    if ((!hard_mem.empty()) && (!ram.empty()) && (!fileout.empty()))
    {
        std::fstream out(fileout);
        std::ifstream ram_elems(ram);
        std::ifstream hard_mem_elems(hard_mem);

        std::multiset<int> ram_set;
        int elem;
        while (ram_elems >> elem)
            ram_set.insert(elem);

        int elem_from_hard_mem;
        hard_mem_elems >> elem_from_hard_mem;

        for (auto item : ram_set)
        {
            while ((!hard_mem_elems.eof()) && (item > elem_from_hard_mem))
            {
                out << elem_from_hard_mem << " ";
                hard_mem_elems >> elem_from_hard_mem;
            }
            out << item << " ";
        }

        if (!hard_mem_elems.eof())
            out << elem_from_hard_mem << hard_mem_elems.rdbuf();

        out.close();
        ram_elems.close();
        hard_mem_elems.close();
    }
}

void filehandler::clear_file(const std::string& filename) const
{
    if (!filename.empty())
        remove(filename.c_str()); // потоки закрыты, поэтому по-другому файлы не удалить(c_str преобразует стринг в с-строку)
}
