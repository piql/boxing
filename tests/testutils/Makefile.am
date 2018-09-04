
lib_LIBRARIES = libtestutils.a
libtestutils_a_CFLAGS = \
	-I${top_srcdir}/inc \
	-I${top_srcdir}/thirdparty/glib \
	-I${top_srcdir}/tests/testutils/inc

libtestutils_a_SOURCES = \
	./inc/unittests.h \
	./inc/boxing_config.h \
	./inc/unboxingutility.h \
	./src/boxing_config.c \
	./src/unboxingutility.c \
    ./src/config_source_4k_controlframe_v1.h \
    ./src/config_source_4k_controlframe_v2.h \
    ./src/config_source_4k_controlframe_v3.h \
    ./src/config_source_4k_controlframe_v4.h \
    ./src/config_source_4k_controlframe_v5.h \
    ./src/config_source_4k_controlframe_v6.h \
    ./src/config_source_4k_controlframe_v7.h \
    ./src/config_source_4kv10.h \
    ./src/config_source_4kv6.h \
    ./src/config_source_4kv7.h \
    ./src/config_source_4kv8.h \
    ./src/config_source_4kv9.h

check_LIBRARIES = libtestutils.a
