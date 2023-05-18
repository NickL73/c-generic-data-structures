#ifndef MAIN_TESTS_H
#define MAIN_TESTS_H

typedef struct testing_substructure_t
{
    int inner_value;
} testing_substructure_t;

typedef struct testing_struct_t
{
    int outer_val;
    testing_substructure_t * p_substruct;
} testing_struct_t;

testing_struct_t * create_new_test_struct (int inner_val, int outer_val);

void * copy_test_struct (const void * p_struct_to_copy);

void destroy_test_struct (const void * p_struct);

int compare_test_structs (const void * p_struct_1, const void * p_struct_2);

void print_test_struct (const void * p_struct);

#endif