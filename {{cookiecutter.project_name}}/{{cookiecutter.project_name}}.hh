#ifndef {{cookiecutter.header_guard_prefix}}APP_HH
#define {{cookiecutter.header_guard_prefix}}APP_HH

#include <vector>
#include <string>

class Application {
    public:
        typedef std::vector<std::string> Args;

    public:
        Application() {}
        ~Application() {}

        int exec(const Args &args);
};

#endif
