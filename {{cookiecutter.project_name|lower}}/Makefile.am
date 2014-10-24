ACLOCAL_AMFLAGS = -I m4

bin_PROGRAMS = {{cookiecutter.project_name|lower}}
{{cookiecutter.project_name|lower}}_SOURCES = main.cc
# CC = @PTHREAD_CC@
{{cookiecutter.project_name|lower}}_CPPFLAGS = \
	$(BOOST_CPPFLAGS) \
	@PTHREAD_CFLAGS@
{{cookiecutter.project_name|lower}}_LDFLAGS = \
	$(BOOST_SYSTEM_LDFLAGS) \
	$(BOOST_THREAD_LDFLAGS)
{{cookiecutter.project_name|lower}}_LDADD = \
	$(BOOST_SYSTEM_LIBS) \
	$(BOOST_THREAD_LIBS) \
	@PTHREAD_CFLAGS@ \
	@PTHREAD_LIBS@

