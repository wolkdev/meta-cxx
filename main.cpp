
#include "path.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "dirent/include/dirent.h"

void lstest(std::string _dirName)
{
    DIR* dir;
    struct dirent* ent;

    /* Open directory stream */
    dir = opendir(_dirName.c_str());
    if (dir != NULL)
    {
        /* Print all files and directories within the directory */
        while ((ent = readdir(dir)) != NULL)
        {
            switch (ent->d_type)
            {
                case DT_REG: printf("%s\n", ent->d_name); break;

                case DT_DIR: printf("%s/\n", ent->d_name); break;

                case DT_LNK: printf("%s@\n", ent->d_name); break;

                default: printf("%s*\n", ent->d_name);
            }
        }

        closedir(dir);
    }
    else
    {
        /* Could not open directory */
        std::cout << "Cannot open dir : " + _dirName << std::endl;
    }
}

// command : meta-cxx *.cpp
// g++ [METAFILES] -o program(.exe)
int main(int argc, char const* argv[])
{
    std::vector<std::string> files;

    for (int i = 1; i < argc; i++)
    {
        std::string file(argv[i]);
        path p(file);
        std::cout << p.filename() << std::endl;
        std::cout << p.directory() << std::endl;
        std::cout << p.extension() << std::endl;
        lstest(p.directory());
        files.push_back(file);
    }

    system("pause");

    return 0;
}