
#include <cstdlib>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sys/stat.h>
#include <sys/types.h>
#include <utility>
#include <vector>

bool file_exist(const std::string& _filePath)
{
    struct stat info;
    return stat(_filePath.c_str(), &info) == 0 && !(info.st_mode & S_IFDIR);
}

std::vector<std::string> get_files_paths(int _argc, char const* _argv[])
{
    std::vector<std::string> paths;
    std::string path;

    for (int i = 1; i < _argc; i++)
    {
        path = _argv[i];

        if (!file_exist(path))
            throw std::runtime_error("error : cannot open \"" + path + "\"");

        paths.push_back(path);
    }

    return paths;
}

// command : meta-cxx *.cpp
// g++ [METAFILES] -o program(.exe)
int main(int _argc, char const* _argv[])
{
    try
    {
        const std::vector<std::string>& paths = get_files_paths(_argc, _argv);

        for (size_t i = 0; i < paths.size(); i++)
        {
            std::cout << "path : " + paths[i] << std::endl;
        }
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    system("pause");

    return 0;
}