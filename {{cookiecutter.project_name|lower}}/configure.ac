AC_PREREQ([2.69])
AC_INIT([{{cookiecutter.project_name|lower}}],[{{cookiecutter.version}}],[{{cookiecutter.email}}])
AC_CONFIG_AUX_DIR([build-aux])
AC_CANONICAL_SYSTEM
AM_INIT_AUTOMAKE([-Wall 1.9 foreign])
AM_MAINTAINER_MODE([enable])

AC_CONFIG_MACRO_DIR([m4])

LT_INIT
AC_SUBST([LIBTOOL_DEPS])

AC_PROG_CXX
AC_PROG_CXX_C_O

AX_CXX_COMPILE_STDCXX_11([noext],[mandatory])
{% if cookiecutter.boost_features %}
BOOST_REQUIRE([1.54])
{% for feature in cookiecutter.boost_features.split(",") -%}
BOOST_{{feature|upper}}
{% endfor -%}
{%- endif  %}
AX_PTHREAD([],[AC_MSG_ERROR([pthread support not available])])

AC_CONFIG_FILES([Makefile])
AC_OUTPUT

