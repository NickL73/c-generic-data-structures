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

#include <stddef.h>
#include <stdint.h>

#include "generics.h"
#include "errors.h"

typedef struct dll_t dll_t;

void test();

dll_t * create_dll (generic_helpers_t * p_funcs, dsa_err_t * p_err);

void destroy_dll (dll_t * p_list, dsa_err_t * p_err);

void clear_dll (dll_t * p_list, dsa_err_t * p_err);

uint32_t get_num_elems (dll_t * p_list, dsa_err_t * p_err);

void delete_element_at_dll (dll_t * p_list, uint32_t index, dsa_err_t * p_err);

void append_dll (dll_t * p_list, void * p_data, dsa_err_t * p_err);

void prepend_dll (dll_t * p_list, void * p_data, dsa_err_t * p_err);

void insert_at_dll (dll_t * p_list, void * p_data, uint32_t index,
                    dsa_err_t * p_err);

void extend_dll (dll_t * p_target, dll_t * p_list, dsa_err_t * p_err);

void * peek_at_dll (dll_t * p_list, uint32_t index, dsa_err_t * p_err);

void * pop_front_dll (dll_t * p_list, dsa_err_t * p_err);

void * pop_back_dll (dll_t * p_list, dsa_err_t * p_err);

uint32_t index_of_dll (dll_t * p_list, void * p_data, dsa_err_t * p_err);

void print_dll (dll_t * p_list, dsa_err_t * p_err);

dll_t * copy_dll (dll_t * p_list, dsa_err_t * p_err);

void sort_dll (dll_t * p_list, dsa_err_t * p_err);

void reverse_dll (dll_t * p_list, dsa_err_t * p_err);

#endif

 /* END OF FILE dll.h*/
