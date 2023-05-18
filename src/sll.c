#include <stddef.h>

#include "errors.h"
#include "generics.h"
#include "sll.h"


structure_status_t create_new_sll (sll_t ** pp_list, 
                                   generic_helpers_t * p_helper_functions)
{
    structure_status_t error_code = GENERIC_FAILURE;
    
    if ((NULL == pp_list) || (NULL == p_helper_functions))
    {
        error_code = NULL_INPUT_ERROR;
        goto COMPLETE;
    }

    sll_t * p_new_sll = calloc(1, sizeof(sll_t));
    if (NULL == p_new_sll)
    {
        error_code = MEMORY_ALLOCATION_FAILURE;
        goto COMPLETE;
    }

    p_new_sll->p_functions = p_helper_functions;

    *pp_list = p_new_sll;
    error_code = FUNCTION_SUCCESS;

COMPLETE:
    return error_code;
}

structure_status_t destroy_sll (sll_t * p_list)
{
    return NOT_YET_IMPLEMENTED;
}

structure_status_t clear_sll (sll_t * p_list)
{
    return NOT_YET_IMPLEMENTED;
}

structure_status_t delete_element_at_sll (sll_t * p_list, uint64_t idx)
{
    return NOT_YET_IMPLEMENTED;
}

structure_status_t append_sll (sll_t * p_list, void * p_data)
{
    return NOT_YET_IMPLEMENTED;
}

structure_status_t prepend_sll (sll_t * p_list, void * p_data)
{
    return NOT_YET_IMPLEMENTED;
}

structure_status_t insert_at_sll (sll_t * p_list, void * p_data)
{
    return NOT_YET_IMPLEMENTED;
}

structure_status_t extend_sll (sll_t * p_target, sll_t * p_to_add)
{
    return NOT_YET_IMPLEMENTED;
}

structure_status_t get_node_at_sll (sll_t * p_list, uint64_t idx, 
                                    void * p_return)
{
    return NOT_YET_IMPLEMENTED;
}

structure_status_t pop_front_sll (sll_t * p_list, void * p_return)
{
    return NOT_YET_IMPLEMENTED;
}

structure_status_t pop_back_sll (sll_t * p_list, void * p_return)
{
    return NOT_YET_IMPLEMENTED;
}

structure_status_t search_sll (sll_t * p_list, void * p_data, uint64_t * p_idx)
{
    return NOT_YET_IMPLEMENTED;
}
