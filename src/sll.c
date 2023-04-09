#include <stdint.h>

#include "errors.h"
#include "generics.h"


structure_status_t create_new_sll (sll_t ** pp_list, 
                                   generic_helpers_t * p_helper_functions);

structure_status_t destroy_sll (sll_t * p_list);

structure_status_t clear_sll (sll_t * p_list);

structure_status_t delete_element_at_sll (sll_t * p_list, uint64_t idx);

structure_status_t append_sll (sll_t * p_list, void * p_data);

structure_status_t prepend_sll (sll_t * p_list, void * p_data);

structure_status_t insert_at_sll (sll_t * p_list, void * p_data);

structure_status_t extend_sll (sll_t * p_target, sll_t * p_to_add);

structure_status_t get_node_at_sll (sll_t * p_list, uint64_t idx, void * p_return);

structure_status_t pop_front_sll (sll_t * p_list, void * p_return);

structure_status_t pop_back_sll (sll_t * p_list, void * p_return);

structure_status_t search_sll (sll_t * p_list, void * p_data, uint64_t * p_idx);
