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

/**
 * @brief Creates a new linked list from the supplied array of integer items.
 * 
 * @param p_items A pointer to an array of integers.
 * @param num_items The number of items in p_items to read into the linked list.
 * 
 * @return Pointer to a new linked list of the given items, in order, or an
 * empty list is no items are supplied.
*/
linked_list_t * create_new_linked_list (int * p_items, size_t num_items);

/**
 * @brief Appends the given integer to the end of the list.
 * 
 * @param item An integer to append to the list.
 * @param p_list Pointer to the linked list to which the new item is appended.
 * 
 * @return 0 if successful, error code otherwise.
*/
uint64_t append_linked_list (int item, linked_list_t * p_list);

/**
 * @brief Prepends the given item to the front of the list.
 * 
 * @param item An integer to prepend to the list.
 * @param p_list Pointer to the linked list to which the item is prepended.
 * 
 * @return 0 if successful, error code otherwise.
*/
uint64_t preprend_linked_list (int item, linked_list_t * p_list);

/**
 * @brief Frees all memory within a linked list and destroys any pointer
 * references.
 * 
 * @param p_list Pointer to linked list to be destroyed.
*/
void destroy_linked_list (linked_list_t * p_list);

/**
 * @brief Deletes the node at the head, or "left", of the linked list.
 * 
 * @param p_list Pointer to the linked list from which to delete the node.
*/
void delete_left_linked_list (linked_list_t * p_list);

/**
 * @brief Deletes the node at the tail, or "right", of the linked list.
 * 
 * @param p_list Pointer to the linked list from which to delete the node.
*/
void delete_right_linked_list (linked_list_t * p_list);

/**
 *@brief Empties all elements from a linked list but maintains its allocated space.
 *
 * @param p_list Pointer to the linked list to be cleared. 
*/
void clear_linked_list (linked_list_t * p_list);

/**
 * @brief Searches a linked list for the given item value.
 * 
 * @param item Integer value of item to search for.
 * @param p_list Pointer to the linked list to search.
 * 
 * @return The index of the first occurence of the input item, or -1 
 * if item not in the list.
*/
int64_t search_linked_list (int item, linked_list_t * p_list);

/**
 * @brief Inserts a given item into a linked list at a specified index.
 * 
 * @param index Index to insert new item at, must be lower than the size of the
 * list and greater than zero.
 * @param item Value of the new item to insert.
 * @param p_list Pointer to the linked list to which to add the new item.
 * 
 * @return 0 on success, error code otherwise.
*/
uint64_t insert_linked_list (uint64_t index, int item, linked_list_t * p_list);

/**
 * @brief Removes the first occurence of the node with the given value.
 * 
 * @param item Item to remove from the linked list.
 * @param p_list Pointer to the linked list from which to remove the node.
 * 
 * @return 0 on success, error code otherwise.
*/
uint64_t remove_item_linked_list (int item, linked_list_t * p_list);

uint64_t combine_linked_list (linked_list_t * p_target, linked_list_t * p_to_add);

linked_list_node_t * get_element_linked_list (uint64_t index, linked_list_t * p_list);

void print_linked_list (linked_list_t * p_list);

//END OF FILE linked_list.h
