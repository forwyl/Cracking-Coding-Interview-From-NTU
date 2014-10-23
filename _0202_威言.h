#ifndef FINDNTHTOLAST_H_INCLUDED
#define FINDNTHTOLAST_H_INCLUDED
#include "LinkedListUtil.h"

/*
2.2 Implement an algorithm to find the nth to last element of a singly linked list.
*/

node* findNthToLast(){

    int i,n;
    node *head = input_list();
    if(head==NULL){
        printf("[Warning] empty list!\n");
        exit(0);
    }
    display_list(head);
    printf("-------------------------------------------------------------------\n");
    printf("Find Nth to the last element(one-based):");
    scanf("%d", &n);
    if(n > siz){
        printf("[Warning] illegal Nth element!\n");
        exit(0);
    }

    node *current = head;
    int counter = 1;
    while(current->next != NULL){
        current = current->next;
        counter++;
    }
    current = head;
    for(i=0; i<(counter-n); i++)
        current = current->next;

    printf("[Result] %dth to the last element is: No:%d, data:%s\n", n, current->no, current->data);

    node *clone = clone_node(current);

    free_list(head);

    return clone;

}

#endif // FINDNTHTOLAST_H_INCLUDED
