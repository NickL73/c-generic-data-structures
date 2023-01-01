#include <stdlib.h>
#include <CUnit/CUnit.h>
#include "../include/linked_list.h"

static uint8_t test_ll_contents (linked_list_t * p_list, int * p_input, size_t len);

void test_create_linked_list (void)
{
    //Check the creation of a simple array of integers
    int p_simple_create_items[] = {1, 2, 3, 4, 5};
    linked_list_t * p_test_list = create_new_linked_list(p_simple_create_items, 5);
    CU_ASSERT_PTR_NOT_NULL(p_test_list); /*Test list is created*/
    CU_ASSERT_PTR_NOT_NULL(p_test_list->p_head); /*Assert the head is there*/
    CU_ASSERT_EQUAL(p_test_list->p_head->data, 1); /*Test correct value at head*/
    CU_ASSERT_EQUAL(p_test_list->size, 5); /*Assert the size is correct*/

    uint8_t contents_check = test_ll_contents(p_test_list, p_simple_create_items, 5);
    CU_ASSERT_EQUAL(contents_check, 1);
    destroy_linked_list(p_test_list);
}

void test_create_empty_list (void)
{
    linked_list_t * p_test = create_new_linked_list(NULL, 0);
    CU_ASSERT_PTR_NOT_NULL(p_test); /*NULL input should produce a list, empty*/
    CU_ASSERT_PTR_NULL(p_test->p_head); /*No elements*/
    CU_ASSERT_EQUAL(p_test->size, 0);

    destroy_linked_list(p_test);

}

void test_append_linked_list (void)
{
    //Create a new linked list
    int p_new_items[] = {1, 2, 3, 4, 5};
    linked_list_t * p_test_list = create_new_linked_list(p_new_items, 5);

    linked_list_node_t * p_old_head = p_test_list->p_head;

    //Append an item and test that it appears at the head, with correct next
    int      new_integer  = 6;
    uint64_t error_status = append_linked_list(new_integer, p_test_list);
    CU_ASSERT_EQUAL(error_status, EXIT_SUCCESS);
    CU_ASSERT_EQUAL(p_test_list->size, 6);
    CU_ASSERT_EQUAL(p_test_list->p_head->data, 1);

    //Iterate to end of the list and check that the node is correct
    linked_list_node_t * p_curr = p_test_list->p_head;
    while (NULL != p_curr->p_next)
    {
        p_curr = p_curr->p_next;
    }

    CU_ASSERT_EQUAL(p_curr->data, new_integer);

    destroy_linked_list(p_test_list);
}

void test_append_empty_list (void)
{
    linked_list_t * p_test = create_new_linked_list(NULL, 0);
    
    uint64_t error_status = append_linked_list(1, p_test);
    CU_ASSERT_PTR_NOT_NULL(p_test->p_head);
    CU_ASSERT_EQUAL(error_status, EXIT_SUCCESS);
    CU_ASSERT_EQUAL(p_test->size, 1);

    destroy_linked_list(p_test);

}

void test_prepend_empty_list (void)
{
    linked_list_t * p_test = create_new_linked_list(NULL, 0);

    uint64_t error_status = preprend_linked_list(1, p_test);

    CU_ASSERT_PTR_NOT_NULL(p_test->p_head);
    CU_ASSERT_EQUAL(p_test->p_head->data, 1);
    CU_ASSERT_EQUAL(error_status, EXIT_SUCCESS);
    CU_ASSERT_EQUAL(p_test->size, 1);

    destroy_linked_list(p_test);
}

void test_prepend_list (void)
{
    int             items[] = {1, 2, 3, 4, 5}; 
    linked_list_t * p_test  = create_new_linked_list(items, 5);

    linked_list_node_t * p_orig_head = p_test->p_head;

    uint64_t error_status = preprend_linked_list(100, p_test);

    CU_ASSERT_EQUAL(error_status, EXIT_SUCCESS);
    CU_ASSERT_PTR_NOT_NULL(p_test->p_head);
    CU_ASSERT_EQUAL(p_test->p_head->data, 100);
    CU_ASSERT_EQUAL(p_test->size, 6);
    CU_ASSERT_PTR_EQUAL(p_test->p_head->p_next, p_orig_head);

    destroy_linked_list(p_test);
}

void test_delete_left_ll(void)
{
    int test_items[] = {1, 2, 3, 4, 5};
    
    linked_list_t *      p_list     = create_new_linked_list(test_items, 5);
    linked_list_node_t * p_expected = p_list->p_head->p_next;

    delete_left_linked_list(p_list);

    CU_ASSERT_EQUAL(p_list->size, 4);
    CU_ASSERT_PTR_EQUAL(p_list->p_head, p_expected);

    destroy_linked_list(p_list);
}

void test_delete_right_ll(void)
{
    int test_items[] = {1, 2, 3, 4, 5};
    
    linked_list_t * p_list = create_new_linked_list(test_items, 5);
    
    linked_list_node_t * p_to_delete = p_list->p_head;
    linked_list_node_t * p_expected  = NULL; //Acts like a "previous" tracker
    while (NULL != p_to_delete->p_next)
    {
        p_expected  = p_to_delete; 
        p_to_delete = p_to_delete->p_next;
    }

    delete_right_linked_list(p_list);

    linked_list_node_t * p_new_tail = p_list->p_head;
    while (NULL != p_new_tail->p_next)
    {
        p_new_tail = p_new_tail->p_next;
    }
 
    CU_ASSERT_EQUAL(p_list->size, 4);
    CU_ASSERT_PTR_NOT_EQUAL(p_new_tail, p_to_delete);
    CU_ASSERT_PTR_EQUAL(p_new_tail, p_expected);

    destroy_linked_list(p_list); 
}

void test_clear_empty_ll(void)
{
    linked_list_t * p_list = create_new_linked_list(NULL, 0);

    clear_linked_list(p_list);

    CU_ASSERT_PTR_NOT_NULL_FATAL(p_list);
    CU_ASSERT_PTR_NULL(p_list->p_head);
    CU_ASSERT_EQUAL(p_list->size, 0);

    destroy_linked_list(p_list);
}

void test_clear_ll(void)
{
    int             list_items[] = {1, 2, 3, 4, 5};
    linked_list_t * p_list       = create_new_linked_list(list_items, 5);

    clear_linked_list(p_list);

    CU_ASSERT_PTR_NOT_NULL_FATAL(p_list);
    CU_ASSERT_PTR_NULL(p_list->p_head);
    CU_ASSERT_EQUAL(p_list->size, 0);

    destroy_linked_list(p_list);
}

void test_search_valid_item_ll(void)
{
    int             list_items[] = {5, 1, 3, 5, 2};
    linked_list_t * p_list       = create_new_linked_list(list_items, 5);

    int64_t index = search_linked_list(3, p_list);
    CU_ASSERT_EQUAL(index, 2);

    index = search_linked_list(5, p_list);
    CU_ASSERT_EQUAL(index, 0);

    destroy_linked_list(p_list);
}

void test_search_invalid_item_ll(void)
{
    int             list_items[] = {5, 1, 3, 5, 2};
    linked_list_t * p_list       = create_new_linked_list(list_items, 5);

    uint64_t index = search_linked_list(4, p_list);
    CU_ASSERT_EQUAL(index, p_list->size);

    destroy_linked_list(p_list);
}

void test_insert_ll(void)
{
    int             list_items[] = {1, 2, 3, 4, 5};
    linked_list_t * p_list       = create_new_linked_list(list_items, 5);

    uint64_t error_status = insert_linked_list(2, 45, p_list);
    
    CU_ASSERT_EQUAL(error_status, EXIT_SUCCESS);
    CU_ASSERT_EQUAL(p_list->size, 6);

    int expected_contents[] = {1, 2, 45, 3, 4, 5};
    uint8_t check_contents = test_ll_contents(p_list, expected_contents, 6);
    CU_ASSERT_EQUAL(check_contents, 1);

    destroy_linked_list(p_list);
}
// void test_insert_insert_invalid_index(void);
// void test_remove_item_ll(void);
// void test_remove_invalid_item(void);
// void test_combine_linked_list(void);
// void test_get_element_ll(void);
// void test_get_element_invalid_index_ll(void);
// //void test_print_linked_list(void);
// void test_delete_linked_list(void);

/*Private Functions*/

/**
 * @brief Helper function that compares the elements of a linked list against
 * the elements in an array of integers, to be used for testing.
 * 
 * @param p_list Pointer to a linked list to test.
 * @param p_input Pointer to an array of integers expected to be in p_list.
 * @param len The length of the list being tested.
 * 
 * @return 1 if all elements match, 0 otherwise.
*/
static uint8_t test_ll_contents (linked_list_t * p_list, int * p_input, size_t len)
{
    int8_t               ret_val = 0;
    linked_list_node_t * p_curr  = p_list->p_head;

    if ((NULL == p_list) || (NULL == p_input))
    {
        goto COMPLETE;
    }

    for (int idx = 0; idx < len; idx++)
    {
        if ((NULL == p_curr) || (p_curr->data != *(p_input + idx)))
        {
            goto COMPLETE;
        }

        p_curr = p_curr->p_next;
    }

    ret_val = 1;

    COMPLETE:
        return ret_val;
}

/*End of file linked_lists_tests.c*/
