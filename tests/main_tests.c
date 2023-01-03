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

    if ((NULL == CU_add_test(ll_test_suite, "create linked list", test_create_linked_list)) ||
        (NULL == CU_add_test(ll_test_suite, "create empty list", test_create_empty_list)) ||
        (NULL == CU_add_test(ll_test_suite, "append to linked list", test_append_linked_list)) ||
        (NULL == CU_add_test(ll_test_suite, "append to empty list", test_append_empty_list)) ||
        (NULL == CU_add_test(ll_test_suite, "prepend to empty list", test_prepend_empty_list)) ||
        (NULL == CU_add_test(ll_test_suite, "prepend linked list", test_prepend_list)) ||
        (NULL == CU_add_test(ll_test_suite, "delete left linked list", test_delete_left_ll)) ||
        (NULL == CU_add_test(ll_test_suite, "delete right linked list", test_delete_right_ll)) ||
        (NULL == CU_add_test(ll_test_suite, "delete of only node in list", test_delete_left_right_one_node_ll)) ||
        // (NULL == CU_add_test(ll_test_suite, "clear linked list", test_clear_ll)) ||
        // (NULL == CU_add_test(ll_test_suite, "clear empty linked list", test_clear_empty_ll)) ||
        // (NULL == CU_add_test(ll_test_suite, "search valid item linked list", test_search_valid_item_ll)) ||
        // (NULL == CU_add_test(ll_test_suite, "invalid search linked list", test_search_invalid_item_ll)) ||
        // (NULL == CU_add_test(ll_test_suite, "valid insert linked list", test_insert_ll)) ||
        // (NULL == CU_add_test(ll_test_suite, "invalid insert linked list", test_insert_insert_invalid_index)) ||
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