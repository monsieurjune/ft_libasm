#include "utils/utils.hpp"

#include <fstream>
#include <filesystem>
#include <exception>
#include <deque>
#include <vector>
#include <utility>
#include <algorithm>

namespace test
{

namespace utils
{

t_cases    get_test_cases(const char* dir)
{
    std::filesystem::path   dir_path(dir);
    t_cases                 str_deque;

    try
    {
        for (auto const& entry : std::filesystem::recursive_directory_iterator(dir_path))
        {
            // check if file is normal file
            if (!entry.is_regular_file())
            {
                continue;
            }

            // open file
            std::ifstream   file(entry.path().c_str());

            if (!file.is_open())
            {
                continue;
            }

            // read file
            std::string                 line;
            std::vector<std::string>    line_vec;

            while (std::getline(file, line))
            {
                line_vec.push_back(line);
            }

            // prevent empty vector
            if (line_vec.size() == 0)
            {
                line_vec.emplace_back("");
                line_vec.emplace_back("");
            }

            // store & close
            str_deque.emplace_back(entry.path().filename().string(), line_vec);
            file.close();
        }
    }
    catch (std::filesystem::filesystem_error const& e)
    {
    }

    // sort pair to make it lexically
    std::sort(str_deque.begin(), str_deque.end());

    return str_deque;
}

}

}
