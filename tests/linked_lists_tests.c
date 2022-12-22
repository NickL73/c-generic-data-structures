#include <stdlib.h>
#include <CUnit/CUnit.h>
#include "../include/linked_list.h"

static uint8_t test_ll_contents (linked_list_t * p_list, int * p_input, size_t len);

void test_create_linked_list(void)
{
    //Check creation on NULL pointer input
    linked_list_t * p_test_list = create_new_linked_list(NULL, 0);
    CU_ASSERT_PTR_NULL(p_test_list->p_head);
    destroy_linked_list(p_test_list);

    //Check the creation of a simple array of integers
    int p_simple_create_items[] = {1, 2, 3, 4, 5};
    p_test_list = create_new_linked_list(p_simple_create_items, 5);
    CU_ASSERT_PTR_NOT_NULL(p_test_list);
    CU_ASSERT_PTR_NOT_NULL(p_test_list->p_head)

    uint8_t contents_check = test_ll_contents(p_test_list, p_simple_create_items, 5);
    CU_ASSERT_EQUAL(contents_check, 1);
    destroy_linked_list(p_test_list);
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
        if ((NULL == p_curr) || (p_curr->p_data != *(p_input + idx)))
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
