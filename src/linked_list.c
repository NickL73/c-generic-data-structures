#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "../include/linked_list.h"

/*Define constants used for error values*/
#define NULL_INP_ERROR      10001
#define ALLOC_FAILURE       10002
#define NODE_CREATE_FAILURE 10003

/*Function Prototypes*/
static linked_list_node_t * create_node (int data);

/*Public Functions*/
linked_list_t * create_new_linked_list (int * p_items, size_t num_items)
{
    linked_list_t * p_new_list = NULL;
    
    // if ((NULL == p_items) || (0 == num_items))
    // {
    //     goto COMPLETE;
    // }
    
    p_new_list = calloc(1, sizeof(linked_list_t));
    if (NULL == p_new_list)
    {
        goto COMPLETE;
    }

    uint8_t error_status = 0;
    for (size_t idx = 0; idx < num_items; idx++)
    {
        error_status = append_linked_list(*(p_items + idx), p_new_list);
    }

    COMPLETE:
        return  p_new_list;
}

uint64_t append_linked_list (int p_item, linked_list_t * p_list)
{
    uint64_t ret_val = 1;
   
    if (NULL == p_list)
    {
        ret_val = NULL_INP_ERROR;
        goto COMPLETE;
    }

    linked_list_node_t * p_new_node = create_node(p_item);
    if (NULL == p_new_node)
    {
        ret_val = NODE_CREATE_FAILURE;
        goto COMPLETE;
    }

    if (NULL == p_list->p_head) //It's an empty list
    {
        p_list->p_head = p_new_node;
        p_list->size += 1;        
    }

    else
    {
        /*Otherwise, traverse to end of the list and append.*/
        linked_list_node_t * p_curr = p_list->p_head;
        while (NULL != p_curr->p_next)
        {
            p_curr = p_curr->p_next;
        }

        p_curr->p_next = p_new_node;
        p_list->size += 1;
    }

    ret_val = EXIT_SUCCESS;

    COMPLETE:
        return ret_val;
}

uint64_t preprend_linked_list (int item, linked_list_t * p_list)
{
    uint64_t ret_val = 0;

    if (NULL == p_list)
    {
        ret_val = NULL_INP_ERROR;
        goto COMPLETE;
    }

    linked_list_node_t * p_new_node = create_node(item);
    if (NULL == p_new_node)
    {
        ret_val = NODE_CREATE_FAILURE;
        goto COMPLETE;
    }

    p_new_node->p_next = p_list->p_head;
    p_list->p_head     = p_new_node;

    p_list->size += 1;

    ret_val = EXIT_SUCCESS;

    COMPLETE:
        return ret_val;

}

void destroy_linked_list (linked_list_t * p_list)
{    
    if (NULL != p_list)
    {
        linked_list_node_t * p_curr = p_list->p_head;

        while (NULL != p_curr)
        {
            linked_list_node_t * p_temp = p_curr;
            p_curr = p_curr->p_next;

            memset(p_temp, 0, sizeof(linked_list_node_t));
            free(p_temp);
            p_temp = NULL;
        }

        memset(p_list, 0, sizeof(linked_list_t));
        free(p_list);
        p_list = NULL;
    }
} 

void delete_left_linked_list (linked_list_t * p_list);

void delete_right_linked_list (linked_list_t * p_list);

void clear_linked_list (linked_list_t * p_list);

int64_t search_linked_list (int item, linked_list_t * p_list);

uint64_t insert_linked_list (uint64_t index, int item, linked_list_t * p_list);

uint64_t remove_item_linked_list (int item, linked_list_t * p_list);

uint64_t combine_linked_list (linked_list_t * p_target, linked_list_t * p_to_add);

linked_list_node_t * get_element_linked_list (uint64_t index, linked_list_t * p_list);

void print_linked_list (linked_list_t * p_list);

/*Private Functions*/
static linked_list_node_t * create_node (int data)
{
    linked_list_node_t * p_new_node = NULL;
    
    p_new_node = calloc(1, sizeof(linked_list_node_t));
    if (NULL == p_new_node)
    {
        goto COMPLETE;
    }

    p_new_node->data = data;
    p_new_node->p_next = NULL;

    COMPLETE:
        return p_new_node;
}
