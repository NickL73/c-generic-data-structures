typedef struct generic_helpers_t
{
    void (*free_func)(void * p_data);
    void * (*copy_func)(const void * p_data);
    int (*compare_func)(const void * p_data_1, const void * p_data_2);
    void (*print_func)(const void * p_data);
} generic_helpers_t;