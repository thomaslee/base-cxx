#!/bin/bash

if [[ "$(./{{cookiecutter.project_name}} | tr -d '\n')" != "Hello World" ]]; then
    echo "Expected 'Hello World'"
    exit 1
fi


