
#include "dynamic_array.h"
#include <stdio.h>

void menu_option(void) {
  printf("========= Welcome =========\n");
  printf("0. Exit\n");
  printf("1. Add data\n");
  printf("2. pop element\n");
  printf("3. add element at\n");
  printf("4. print array\n");
}

void add_value(DynamicArray *arr) {

  int value;
  printf("Enter a value : ");
  scanf("%d", &value);

  if (push_back(arr, value)) {
    printf("Data added successfully \n");
    printf("Size = %d\n", arr->size);
  } else {
    printf("Simething went wrong\n");
  }
}

void add_element_at(DynamicArray *arr) {
  int index;
  int value;

  printf("Enter index : \n");
  scanf("%d", &index);

  printf("Enter value : \n");
  scanf("%d", &value);

  if (insert_at(arr, index, value)) {
    printf("element inserted successfully");
  } else {
    printf("Something went wrong");
  }
}

void start_ui(DynamicArray *arr) {

  int option;
  do {
    menu_option();
    scanf("%d", &option);
    switch (option) {
    case 0:
      printf("Exiting...\n");
      break;

    case 1:
      add_value(arr);
      break;
    case 2:
      pop_back(arr);
      break;
    case 3:
      add_element_at(arr);
      break;
    case 4:
      print_array(arr);
      break;

    default:
      printf("Invalid option\n");
    }
  } while (option != 0);
}