#include "ui.h"
#include <stdio.h>
#include <stdlib.h>
#include "dynamic_array.h"
void menu_option(void) {
 printf("========= Welcome =========\n");
 printf("0. Exit\n");
 printf("1. Add data\n");
}

void add_value(void) {
 DynamicArray arr;
 int value;
 printf("Enter a value : ");
 scanf("%d", &value);

 if(push_back(&arr, value)) {
  printf("Data added successfully \n");
 }else {
  printf("Simething went wrong\n");
 }
}

void start_ui(void) {
 
 int option;
 do{
 menu_option();
 scanf("%d", &option);
 switch(option) {
  case 1:
  add_value();
  break;
  default:
  printf("Invalid option\n");
 }
 }while(option != 0);

}