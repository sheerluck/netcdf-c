## This is a automake file, part of Unidata's netCDF package.
# Copyright 2018, see the COPYRIGHT file for more information.

# This file builds and runs DAP4 tests.

# Put together AM_CPPFLAGS and AM_LDFLAGS.
include $(top_srcdir)/lib_flags.am

TESTS_ENVIRONMENT =

#TEST_EXTENSIONS = .sh

#SH_LOG_DRIVER = $(SHELL) $(top_srcdir)/test-driver-verbose
#sh_LOG_DRIVER = $(SHELL) $(top_srcdir)/test-driver-verbose
#LOG_DRIVER = $(SHELL) $(top_srcdir)/test-driver-verbose
#TESTS_ENVIRONMENT += export SETX=1;

AM_CPPFLAGS += -I${top_srcdir} -I${top_srcdir}/libnczarr
AM_LDFLAGS += ${top_builddir}/liblib/libnetcdf.la
LDADD = ${top_builddir}/liblib/libnetcdf.la

# Set up the tests; do the .sh first, then .c
check_PROGRAMS =
TESTS =

check_PROGRAMS += ut_map ut_mapapi ut_json ut_projections ut_chunking 

commonsrc = ut_util.c ut_test.c ut_includes.h ut_test.h ut_util.h test_nczarr_utils.h

ut_map_SOURCES = ut_map.c ${commonsrc}
ut_mapapi_SOURCES = ut_mapapi.c ${commonsrc}
ut_json_SOURCES = ut_json.c ${commonsrc}
ut_projections_SOURCES = ut_projections.c ${commonsrc}
ut_chunking_SOURCES = ut_chunking.c ${commonsrc}

check_PROGRAMS += tst_chunks tst_chunks2 tst_chunks3 tst_fillonlyz

TESTS += run_ut_map.sh
TESTS += run_ut_mapapi.sh
TESTS += run_ut_misc.sh
TESTS += run_ut_chunk.sh

if BUILD_UTILITIES

if USE_HDF5
TESTS += tst_nccopyz.sh
TESTS += run_it_test1.sh
TESTS += test_fillonlyz.sh
endif
TESTS += run_it_test2.sh

endif #BUILD_UTILITIES

ignorec = ut_allslices.c ut_transfer.c ut_vars.c ut_walk.c
ignoresh = run_meta_tests.sh run_unittests.sh
ignoreh = ut_varstest.h

# These programs are used by the test cases
noinst_PROGRAMS = zmapio
zmapio_SOURCES = zmapio.c
noinst_PROGRAMS += zhex
zhex_SOURCES = zhex.c
noinst_PROGRAMS += zisjson
zisjson_SOURCES = zisjson.c
noinst_PROGRAMS += zs3parse
zs3parse_SOURCES = zs3parse.c

EXTRA_DIST = \
run_ut_map.sh run_ut_mapapi.sh run_ut_misc.sh run_ut_chunk.sh run_it_test1.sh run_it_test2.sh \
test_nczarr.sh tst_nccopyz.sh \
ref_ut_map_readmeta_nzf.txt \
ref_ut_map_writedata_nzf.cdl \
ref_ut_map_writemeta_nzf.cdl \
ref_ut_map_writemeta_nz4.cdl \
ref_ut_map_writedata_nz4.cdl \
ref_ut_map_write2meta_nzf.cdl \
ref_ut_map_write2meta_nz4.cdl \
ref_ut_map_search_nzf.txt \
ref_ut_map_search_nz4.txt \
ref_ut_map_readmeta_nz4.txt \
ref_ut_map_readdata_nz4.txt \
ref_ut_map_create_nz4.cdl \
ref_ut_json_parse.txt \
ref_ut_json_build.txt \
ref_t_meta_var1.cdl \
ref_t_meta_dim1.cdl \
ref_ut_testmap_create_nz4.cdl \
ref_ut_proj.txt \
ref_ut_map_create_nzf.cdl \
ref_ut_mapapi_create_nz4.cdl \
ref_ut_mapapi_create_nzf.cdl \
ref_ut_mapapi_create_s3.cdl \
ref_ut_mapapi_data_nz4.cdl \
ref_ut_mapapi_data_nzf.cdl \
ref_ut_mapapi_data_s3.cdl \
ref_ut_mapapi_meta_nz4.cdl \
ref_ut_mapapi_meta_nzf.cdl \
ref_ut_mapapi_meta_s3.cdl \
ref_ut_mapapi_search_nz4.txt \
ref_ut_mapapi_search_nzf.txt \
ref_ut_mapapi_search_s3.txt \
ref_perdimspecs.cdl \
ref_fillonly.cdl test_fillonlyz.sh

CLEANFILES = test.nzf test.nz4 test.nz4 \
testmap.nzf testmap.nz4 testmapapi.nzf testmapapi.nz4 \
tst_chunks.nz4 tst_chunks2.nc.nz4 \
ut_*.txt ut*.cdl tmp*.nc tmp*.cdl *.dmp test.nzf \
tst_chunks3.nc

if AX_IGNORE
if BUILD_BENCHMARKS

BMCOMMON=bm_utils.c ut_util.c ut_test.c

if AX_IGNORE
BENCHMARKS = bm_chunks3 bm_many_atts bm_many_objs
bm_chunks3_SOURCES = bm_chunks3.c ${BMCOMMON}
bm_many_atts_SOURCES = bm_many_atts.c ${BMCOMMON}
bm_many_objs_SOURCES = bm_many_objs.c ${BMCOMMON}
else
BENCHMARKS = bm_many_atts bm_many_objs
bm_many_atts_SOURCES = bm_many_atts.c ${BMCOMMON}
bm_many_objs_SOURCES = bm_many_objs.c ${BMCOMMON}
endif

#PG = -pg
AM_CFLAGS += ${PG}
AM_LDFLAGS += ${PG}

check_PROGRAMS += ${BENCHMARKS}
TESTS += run_bm_many_atts.sh
TESTS += run_bm_many_objs.sh

EXTRA_DIST += bm_common.sh run_bm_metatest.sh run_bm_many_atts.sh run_bm_many_objs.sh

CLEANFILES += bm_many_atts.nc4 bm_many_atts.nzf
CLEANFILES += bm_many_objs.nc4 bm_many_objs.nzf

endif
endif

# Remove directories
clean-local:
	rm -fr tst_chunks.nzf tst_chunks2.nzf tst_perdimspecs.nzf testmap.nzf testmapapi.nzf test.nzf
	rm -fr bm_many_*.nzf
	
