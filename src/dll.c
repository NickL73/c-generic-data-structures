/**
 * @file dll.c
 * @author Nicholas Lunsford
 * @brief This file implements the functionality of a doubly-linked list with
 * generic types.
 * @version 1.0.0
 * @date 2023-11-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */
 
#include "dll.h"


typedef struct dll_node_t
{
    void * p_data;
    struct dll_node_t * p_next;
    struct dll_node_t * p_prev;
} dll_node_t;

typedef struct dll_t
{
    uint32_t num_elem;
    generic_helpers_t * p_functions;
    dll_node_t * p_head;
} dll_t;

void test()
{
    return;
}

dll_t * create_dll (generic_helpers_t * p_funcs, dsa_err_t * p_err)
{
    return NULL;
}

void destroy_dll (dll_t * p_list, dsa_err_t * p_err)
{
    return;
}

void clear_dll (dll_t * p_list, dsa_err_t * p_err)
{
    return;
}

uint32_t get_num_elems (dll_t * p_list, dsa_err_t * p_err)
{
    return 0;
}

void delete_element_at_dll (dll_t * p_list, uint32_t index, dsa_err_t * p_err)
{
    return;
}

void append_dll (dll_t * p_list, void * p_data, dsa_err_t * p_err)
{
    return;
}

void prepend_dll (dll_t * p_list, void * p_data, dsa_err_t * p_err)
{
    return;
}

void insert_at_dll (dll_t * p_list, void * p_data, uint32_t index,
                    dsa_err_t * p_err)
{
    return;
}

void extend_dll (dll_t * p_target, dll_t * p_list, dsa_err_t * p_err)
{
    return;
}

void * peek_at_dll (dll_t * p_list, uint32_t index, dsa_err_t * p_err)
{
    return NULL;
}

void * pop_front_dll (dll_t * p_list, dsa_err_t * p_err)
{
    return NULL;
}

void * pop_back_dll (dll_t * p_list, dsa_err_t * p_err)
{
    return NULL;
}

uint32_t index_of_dll (dll_t * p_list, void * p_data, dsa_err_t * p_err)
{
    return 0;
}

void print_dll (dll_t * p_list, dsa_err_t * p_err)
{
    return;
}

dll_t * copy_dll (dll_t * p_list, dsa_err_t * p_err)
{
    return NULL;
}

void sort_dll (dll_t * p_list, dsa_err_t * p_err)
{
    return;
}

void reverse_dll (dll_t * p_list, dsa_err_t * p_err)
{
    return;
}


 /* END OF FILE dll.c */