#ifndef PATH__HPP
#define PATH__HPP

#include <string>
#include <vector>

class path
{
    private:
    std::string str;

    public:
    path(const char* _str) : str(_str) { }
    path(const std::string& _str) : str(_str) { }

    std::string filename();
    std::string directory();
    std::string extension();

    std::vector<path> get_paths();
};

#endif // !PATH__HPP