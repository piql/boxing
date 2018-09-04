#include "unittests.h"
#include "boxing/utils.h"


#if defined ( D_OS_WIN32 )
#   define _CRTDBG_MAP_ALLOC
#   include <crtdbg.h>
#   include <stdlib.h>
#endif

extern Suite * config_test();
extern Suite * frametrackerutil_test();
extern Suite * math_tests();
extern Suite * metadata_tests();
extern Suite * image8_tests();
extern Suite * matrix_tests();
extern Suite * string_tests();
extern Suite * boxer_tests();
extern Suite * crc32_tests();

void boxing_log(int log_level, const char * message) 
{
    BOXING_UNUSED_PARAMETER( message );
    BOXING_UNUSED_PARAMETER( log_level );
}

void boxing_log_args(int log_level, const char * message, ...) 
{
    BOXING_UNUSED_PARAMETER( message );
    BOXING_UNUSED_PARAMETER( log_level );
}

Suite * make_master_suite( void )
{
    return suite_create( "unboxinglib" );
}

int main(int argc, char ** argv)
{
    BOXING_UNUSED_PARAMETER( argv );
    BOXING_UNUSED_PARAMETER( argc );

#if defined ( D_OS_WIN32 )
    //_CrtSetBreakAlloc(2012);
#endif

    int number_failed;
    SRunner *sr;

    sr = srunner_create(make_master_suite());
    srunner_set_xml( sr, "unboxingdata.xml" );

    // Add all test suites here
    srunner_add_suite(sr, config_test());
    //srunner_add_suite(sr, frametrackerutil_test());
    srunner_add_suite(sr, math_tests());
    srunner_add_suite(sr, metadata_tests());
    srunner_add_suite(sr, image8_tests());
    srunner_add_suite(sr, matrix_tests());
    srunner_add_suite(sr, string_tests());
    //srunner_add_suite(sr, boxer_tests());
    srunner_add_suite(sr, crc32_tests());
 
    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;

#if defined ( D_OS_WIN32 )
    //_CrtDumpMemoryLeaks();
#endif
}
