#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

void init_array(DynamicArray *arr){
 arr -> capacity = 4; 
 arr -> size = 0;
 
 arr -> data = (int *)malloc(arr -> capacity * sizeof(int));
 if (arr -> data == NULL){
  printf("memory allocation failed\n");
  exit(EXIT_FAILURE);
 }
}
// after init array size is 16 bytes and capacity is 4 

bool_t push_back(DynamicArray *arr, int value)
{
    if (arr->size == arr->capacity)
    {
        arr->capacity *= 2;

        int *temp = realloc(arr->data, arr->capacity * sizeof(int));

        if (temp == NULL)
        {
            printf("Memory reallocation failed!\n");
 
            return FALSE;
        }

        arr->data = temp;
    }

    arr->data[arr->size] = value;
    arr->size++;
    return TRUE;
}

