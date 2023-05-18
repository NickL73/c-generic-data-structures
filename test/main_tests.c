#include <CUnit/Basic.h>
#include <CUnit/CUnit.h>

#include "main_tests.h"

extern CU_TestInfo sll_tests[];

int main (void)
{
    CU_SuiteInfo data_structures_test_suite[] = {
        {"SLL Tests", NULL, NULL, NULL, NULL, sll_tests},
        CU_SUITE_INFO_NULL
    };

    CU_initialize_registry();

    CU_register_suites(data_structures_test_suite);
    CU_basic_set_mode(CU_BRM_VERBOSE);

    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}

testing_struct_t * create_new_test_struct (int inner_val, int outer_val)
{
    testing_struct_t * p_struct = calloc(1, sizeof(testing_struct_t));
    if (NULL == p_struct)
    {
        goto COMPLETE;
    }

COMPLETE:
}

void * copy_test_struct (const void * p_struct_to_copy);

void destroy_test_struct (const void * p_struct);

int compare_test_structs (const void * p_struct_1, const void * p_struct_2);

void print_test_struct (const void * p_struct);
