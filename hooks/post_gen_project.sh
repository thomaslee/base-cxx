#!/bin/bash

set -e

echo "Ensuring we can generate Makefiles and run smoke tests ..."

set -x
cmake .
make check

set +x
echo "Everything looks good."

if [[ "{{cookiecutter.version_control}}" == "git" ]]; then
    git init
    git add .
    git commit -a -m "Initial import"
fi

