#ifndef COUNTVALUEFROMLIST_H_INCLUDED
#define COUNTVALUEFROMLIST_H_INCLUDED
#include "LinkedListUtil.h"
/*
2.4 You have two numbers represented by a linked list, where each node contains a single digit.
The digits are stored in reverse order, such that the 1¡¦s digit is at the head of the list.
Write a function that adds the two numbers and returns the sum as a linked list. EXAMPLE
Input: (3 -> 1 -> 5) + (5 -> 9 -> 2) Output: 8 -> 0 -> 8
*/

int count_value_list();
int convert_list_integer(node *head, int list_size);

int count_value_list(){

    int first_size, second_size;
    int first_number = 0;
    int second_number = 0;

    //first input
    printf("------First input list------\n");
    node *first_input = input_list();
    first_size = count_size(first_input);
    //second input
    printf("------Second input list------\n");
    node *second_input = input_list();
    second_size = count_size(second_input);
    display_list(first_input);
    display_list(second_input);
    first_input = reverse_list(first_input); //reverse the first one and count its size
    second_input = reverse_list(second_input); //reverse the second one and count its size
    printf("------First input list in reverse order, size:%d ------\n", first_size);
    display_list(first_input);
    printf("------Second Input list in reverse order, size:%d ------\n", second_size);
    display_list(second_input);

    first_number = convert_list_integer(first_input, first_size); //convert the first one to integer
    second_number = convert_list_integer(second_input, second_size); //convert the second one to integer
    printf("[Result]sum of the two number is : %d\n", first_number+second_number);

    free_list(first_input);
    free_list(second_input);

    return first_number+second_number;

}

int convert_list_integer(node *head, int list_size){

    int i=0;
    int j=0;
    int sum = 0;
    node *temp = NULL;
    int ten_counter = 1;

    temp = head;
    for(i,j;i<list_size; i++){
        if(i>0){
            while(j++<i){
                ten_counter = ten_counter*10;
            }
            sum += atoi(temp->data)*ten_counter;
            ten_counter = 1;
            j = 0;
        }else{
            sum += atoi(temp->data);
        }
        temp = temp->next;
    }

    return sum;
}

#endif // COUNTVALUEFROMLIST_H_INCLUDED
