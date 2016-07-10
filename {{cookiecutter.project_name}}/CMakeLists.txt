cmake_minimum_required(VERSION 3.1.0)

set(PROJECT_NAME {{cookiecutter.project_name}})
set(SOURCE_EXTENSION {{cookiecutter.source_extension}})
{%if cookiecutter.cxx_standard%}
set(CMAKE_CXX_STANDARD {{cookiecutter.cxx_standard}})
{%endif%}
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_VERBOSE_MAKEFILE ON)

project(${PROJECT_NAME})

find_package(Threads)

file(GLOB SOURCES_AND_MAIN *.${SOURCE_EXTENSION})
foreach(filename ${SOURCES_AND_MAIN})
    if("${filename}" MATCHES "main\\.${SOURCE_EXTENSION}\$")
        message("found main")
    elseif("${filename}" MATCHES "test_.*\\.${SOURCE_EXTENSION}\$")
        message("found test source: ${filename}")
        list(APPEND TEST_SOURCES ${filename})
    else()
        message("found source: ${filename}")
        list(APPEND SOURCES ${filename})
    endif()
endforeach()

# FIXME
if("${SOURCES}" MATCHES ".+")
    set(BUILD_STATIC_LIB 1)
else()
    set(BUILD_STATIC_LIB 0)
endif()

if(${BUILD_STATIC_LIB} EQUAL 1)
    add_library(${PROJECT_NAME}-static STATIC ${SOURCES})
endif()

{%if cookiecutter.project_type == "executable"%}
add_executable(${PROJECT_NAME} main.${SOURCE_EXTENSION})
if(${BUILD_STATIC_LIB} EQUAL 1)
    target_link_libraries(${PROJECT_NAME} ${PROJECT_NAME}-static)
endif()
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
{%else%}
add_library(${PROJECT_NAME} ${SOURCES})
{%endif%}

add_subdirectory(vendor/gtest/1.7.0 EXCLUDE_FROM_ALL)

enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(test_${PROJECT_NAME} ${TEST_SOURCES}
    ${gtest_SOURCE_DIR}/src/gtest-all.cc
    ${gtest_SOURCE_DIR}/src/gtest_main.cc)
target_link_libraries(test_${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})
if(${BUILD_STATIC_LIB} EQUAL 1)
    target_link_libraries(test_${PROJECT_NAME} ${PROJECT_NAME}-static)
endif()

add_test(${PROJECT_NAME}-test test_${PROJECT_NAME} --gtest_color=yes)

file(GLOB TEST_SCRIPTS test_*.sh)
foreach(filename ${TEST_SCRIPTS})
    message("found test script: ${filename}")
    add_test(${PROJECT_NAME}-test-${filename} ${filename})
endforeach()

add_custom_target(check COMMAND ${CMAKE_CTEST_COMMAND} --verbose DEPENDS test_${PROJECT_NAME} ${PROJECT_NAME})

