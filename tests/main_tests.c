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

    if ((NULL == CU_add_test(ll_test_suite, "test create linked list", test_create_linked_list)) ||
        (NULL == CU_add_test(ll_test_suite, "test create empty list", test_create_empty_list)) ||
        (NULL == CU_add_test(ll_test_suite, "test append to linked list", test_append_linked_list)) ||
        (NULL == CU_add_test(ll_test_suite, "test append to empty list", test_append_empty_list)) ||
        (NULL == CU_add_test(ll_test_suite, "test prepend to empty list", test_prepend_empty_list)) ||
        (NULL == CU_add_test(ll_test_suite, "test prepend linked list", test_prepend_list)) ||
        (NULL == CU_add_test(ll_test_suite, "test delete left linked list", test_delete_left_ll)) ||
        (NULL == CU_add_test(ll_test_suite, "test delete right linked list", test_delete_right_ll)) ||
        (NULL == CU_add_test(ll_test_suite, "test clear linked list", test_clear_ll)) ||
        (NULL == CU_add_test(ll_test_suite, "test clear empty linked list", test_clear_empty_ll)) ||
        (NULL == CU_add_test(ll_test_suite, "test search valid item linked list", test_search_valid_item_ll)) ||
        (NULL == CU_add_test(ll_test_suite, "test invalid search linked list", test_search_invalid_item_ll)) ||
        (NULL == CU_add_test(ll_test_suite, "test valid insert linked list", test_insert_ll)) ||
        (NULL == CU_add_test(ll_test_suite, "test invalid insert linked list", test_insert_insert_invalid_index)) ||
        (0 == 1)
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