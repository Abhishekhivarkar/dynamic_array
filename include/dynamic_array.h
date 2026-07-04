#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
typedef struct {
 int *data;
 int size;
 int capacity;
} DynamicArray;

typedef enum {
 FALSE = 0,
 TRUE = 1
} bool_t;

void init_array(DynamicArray *arr);
bool_t push_back(DynamicArray *arr,int value);
void pop_back(DynamicArray *arr);
void insert_at(DynamicArray *arr, int index, int value);
void delete_at(DynamicArray *arr, int index, int value);
void print_array(DynamicArray *arr);
void free_array(DynamicArray *arr);

#endif