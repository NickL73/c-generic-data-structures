#include <stddef.h>
#include <stdint.h>

//Define error values for checking function failures
#define NULL_INPUT 9
#define CALLOC_FAIL 8

typedef struct linked_list_node_t
{
    int                         data;
    struct linked_list_node_t * p_next;
} linked_list_node_t;

typedef struct linked_list_t
{
    linked_list_node_t * p_head;
    size_t               size;
} linked_list_t;

linked_list_t * create_new_linked_list (int * p_items, size_t num_items);

uint64_t append_linked_list (int item, linked_list_t * p_list);
uint64_t preprend_linked_list (int item, linked_list_t * p_list);
uint64_t destroy_linked_list (linked_list_t * p_list);