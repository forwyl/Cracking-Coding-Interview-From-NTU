#ifndef DELETEUNKNOWNNODE_H_INCLUDED
#define DELETEUNKNOWNNODE_H_INCLUDED
#include "LinkedListUtil.h"

/*
2.3 Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node.
 EXAMPLE Input: the node !¢Dc!| from the linked list a->b->c->d->e Result: nothing is returned, but the new linked
 list looks like a->b->d->e
*/

void delete_unknown_Node(){

    int index;
    node *head = input_list();
    display_list(head);
    printf("Choose a node you want to remove. Its index is: ");
    scanf("%d", &index);
    node *middle = find_Nth(head, index);
    printf("The chosen node is No: %d, String: %s \n", middle->no, middle->data);

    if(middle->next == NULL){
        printf("[Warning] this is the tail! \n");
        exit(0);
    }

    node *temp = middle->next;
    strncpy(middle->data, middle->next->data, sizeof(middle->next->data)-1);
    middle->data[sizeof(middle->next->data)-1] = '\0';
    middle->no = middle->next->no;
    middle->next = middle->next->next;
    free(temp);

    printf("Show the list after removing No.%d node \n", index);
    display_list(head);
    free_list(head);

}

#endif // DELETEUNKNOWNNODE_H_INCLUDED
