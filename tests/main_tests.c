#include <stdio.h>
#include <stdlib.h>
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/CUnitCI.h>
#include "linked_lists_tests.h"

int main (int argc, char * argv[])
{
    if (CUE_SUCCESS != CU_initialize_registry())
    {
        return CU_get_error();
    }

    CU_pSuite ll_test_suite = CU_add_suite("Linked List Tests", NULL, NULL);

    if (NULL == ll_test_suite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(ll_test_suite, "test of create linked list", test_create_linked_list)) ||
        (NULL == CU_add_test(ll_test_suite, "test of create empty list", test_create_empty_list)) ||
        (NULL == CU_add_test(ll_test_suite, "test of append to linked list", test_append_linked_list)) ||
        (NULL == CU_add_test(ll_test_suite, "testing append to empty list", test_append_empty_list))
        )
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_set_mode(CU_BRM_VERBOSE);

    if (argc >= 1)
    {
        CU_set_output_filename(argv[0]);
    }

    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}