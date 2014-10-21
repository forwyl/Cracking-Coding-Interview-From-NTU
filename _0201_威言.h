#ifndef REMOVEDUPLICATEINLIST_H_INCLUDED
#define REMOVEDUPLICATEINLIST_H_INCLUDED
#include "LinkedListUtil.h"

/*
2.1 Write code to remove duplicates from an unsorted linked list.
FOLLOW UP How would you solve this problem if a temporary buffer is not allowed?
*/

void removeDuplicatesInListNoBuf(){

    node *head = input_list();
    node *current = head;
    node *after, *temp, *previous;
    char data[LEN];

    while(current != NULL){
        previous = current;
        after = current->next;
        while(after != NULL){
            if(strcmp(current->data,after->data) == 0){
                temp = after->next;
                previous->next = temp;
                temp = after;
                after = previous->next;
                free(temp);
            }else{
                previous = after;
                after = after->next;
            }
        }
        current = current->next;
    }

    display_list(head);
    free_list(head);

}

#endif // REMOVEDUPLICATEINLIST_H_INCLUDED
