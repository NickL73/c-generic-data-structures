/**
 * @file dll.h
 * @author Nicholas Lunsford
 * @brief Contains function declarations and structure definitions for the 
 * doubly-linked list data structure.
 * @version 1.0.0
 * @date 2023-11-17
 * 
 * @copyright Copyright (c) 2023
 * 
 */

 #ifndef DLL_H
 #define DLL_H

#include "errors.h"

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


dll_t create_dll (generic_helpers_t * p_funcs, dsa_err_t * p_err);

void destroy_dll (dll_t * p_list, dsa_err_t * p_err);

void clear_dll (dll_t * p_list, dsa_err_t * p_err);

void delete_element_at_dll (dll_t * p_list, uint32_t index, dsa_err_t * p_err);

void append_dll (dll_t * p_list, void * p_data, dsa_err_t * p_err);

void prepend_dll (dll_t * p_list, void * p_data, dsa_err_t * p_err);

void insert_at_dll (dll_t * p_list, void * p_data, uint32_t index,
                    dsa_err_t * p_err);

void extend_dll (dll_t * p_target, dll_t * p_list, dsa_err_t * p_err);

dll_node_t * peek_at_dll (dll_t * p_list, uint32_t index, dsa_err_t * p_err);

dll_node_t * pop_front_dll (dll_t * p_list, dsa_err_t * p_err);

dll_node_t * pop_back_dll (dll_t * p_list, dsa_err_t * p_err);

uint32_t index_of_dll (dll_t * p_list, void * p_data, dsa_err_t * p_err);

void print_dll (dll_t * p_list, dsa_err_t * p_err);

dll_t * copy_dll (dll_t * p_list, dsa_err_t * p_err);

void sort_dll (dll_t * p_list, dsa_err_t * p_err);

void reverse_dll (dll_t * p_list, dsa_err_t * p_err);

#endif

 /* END OF FILE dll.h*/
