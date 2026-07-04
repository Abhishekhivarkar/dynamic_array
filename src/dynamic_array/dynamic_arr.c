#include "dynamic_array.h"
#include <stdio.h>
#include <stdlib.h>

void init_array(DynamicArray *arr) {
  arr->capacity = 4;
  arr->size = 0;

  arr->data = (int *)malloc(arr->capacity * sizeof(int));
  if (arr->data == NULL) {
    printf("memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
}
// after init array size increases to 16 bytes and capacity increase to 4

bool_t push_back(DynamicArray *arr, int value) {
  if (arr->size == arr->capacity) {
    arr->capacity *= 2;

    int *temp = realloc(arr->data, arr->capacity * sizeof(int));

    if (temp == NULL) {
      printf("Memory reallocation failed!\n");

      return FALSE;
    }

    arr->data = temp;
  }

  arr->data[arr->size] = value;
  arr->size++;
  return TRUE;
}

bool_t pop_back(DynamicArray *arr) {
  if (arr->size == 0) {
    printf("Array is empty");
    return FALSE;
  }
  arr->size--;
  return TRUE;
}

bool_t print_array(DynamicArray *arr) {
  if (arr->size == 0) {
    printf("Array is empty\n");
    return FALSE;
  }
  printf("[");
  for (int i = 0; i < arr->size; i++) {
    printf("%d", arr->data[i]);

    if (i != arr->size - 1) {
      printf(",");
    }
  }
  printf("]");
  printf("%zu\n", sizeof(arr->data) * 4);
  return TRUE;
}

bool_t insert_at(DynamicArray *arr, int index, int value) {
  if (arr->size == arr->capacity) {
    arr->capacity *= 2;

    int *temp = realloc(arr->data, arr->capacity * sizeof(int));

    if (temp == NULL) {
      printf("Failed to re allocate memory");
      return FALSE;
    }

    arr -> data = temp;
  }

  for (int i = arr->size; i > index; i--) {
    arr->data[i] = arr->data[i - 1];
  }

  arr->data[index] = value;
  arr->size++;

  return TRUE;
}