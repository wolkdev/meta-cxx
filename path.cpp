
#include "path.hpp"

#include "dirent/include/dirent.h"

std::string path::filename()
{
    size_t slashPos = str.find_last_of("/\\");
    size_t dotPos = str.find_last_of('.');

    size_t start = slashPos != std::string::npos ? slashPos + 1 : 0;
    size_t end = dotPos != std::string::npos ? dotPos : str.length();

    return str.substr(start, end - start);
}

std::string path::directory()
{
    size_t slashPos = str.find_last_of("/\\");

    if (slashPos != std::string::npos)
    {
        return str.substr(0, slashPos);
    }

    return std::string();
}

std::string path::extension()
{
    size_t slashPos = str.find_last_of("/\\");
    size_t dotPos = str.find_last_of('.');

    if ((slashPos == std::string::npos || slashPos < dotPos)
        && dotPos != std::string::npos)
    {
        size_t start = dotPos + 1;

        return str.substr(start, str.length() - start);
    }

    return std::string();
}

std::vector<path> path::get_paths()
{
    std::vector<path> paths;

    std::string fileName = filename();
    std::string dirName = directory();

    if (fileName == "*")
    {

    }
    else if (fileName == "**")
    {

    }

    return paths;
}