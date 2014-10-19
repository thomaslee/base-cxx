ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = {{cookiecutter.project_name|lower}}
{{cookiecutter.project_name|lower}}_SOURCES = main.cc
# CC = @PTHREAD_CC@
AM_CPPFLAGS = $(BOOST_CPPFLAGS) @PTHREAD_CFLAGS@
AM_LDFLAGS = $(BOOST_SYSTEM_LDFLAGS)
AM_LIBS = $(BOOST_SYSTEM_LIBS) @PTHREAD_LIBS@

