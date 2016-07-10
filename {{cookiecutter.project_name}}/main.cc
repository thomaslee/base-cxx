#include "{{cookiecutter.project_name}}.hh"

int
main (int argc, char **argv)
{
    Application::Args args;

    for (int i = 0; i < argc; i++) {
        args.push_back(argv[i]);
    }

    Application app;
    return app.exec(args);
}

