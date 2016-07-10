#include <iostream>

#include "{{cookiecutter.project_name}}.hh"

int
Application::exec(const Application::Args &args)
{
    std::cout << "Hello World" << std::endl;
    return 0;
}

