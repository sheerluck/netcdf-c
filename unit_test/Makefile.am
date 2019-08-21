## This is a automake file, part of Unidata's netCDF package.
# Copyright 2019, see the COPYRIGHT file for more information.

# This file builds and runs the unit tests. These tests are not run in
# the CMake build, because we would then have to extern these internal
# functions, to allow Windows to work. Since we have not extern'd
# these functions, they will only be run under the autotools build.

# Ed Hartnett 8/9/19

# Put together AM_CPPFLAGS and AM_LDFLAGS.
include $(top_srcdir)/lib_flags.am

# Find and link to the netcdf-c library.
LDADD = ${top_builddir}/liblib/libnetcdf.la

check_PROGRAMS = tst_nclist
TESTS = tst_nclist

# If valgrind is present, add valgrind targets.
@VALGRIND_CHECK_RULES@