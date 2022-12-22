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
    CU_ASSERT_PTR_NOT_NULL(p_test);
    CU_ASSERT_PTR_NULL(p_test->p_head);
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
