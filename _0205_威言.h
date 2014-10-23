#ifndef FINDBEGIN_H_INCLUDED
#define FINDBEGIN_H_INCLUDED
#include "LinkedListUtil.h"
/*
2.5 Given a circular linked list, implement an algorithm which returns node at the beginning of the loop.
 DEFINITION Circular linked list: A (corrupt) linked list in which a node¡¦s next pointer points to an
 earlier node, so as to make a loop in the linked list. EXAMPLE input: A -> B -> C -> D -> E -> C (the
 same C as earlier) output: C
*/


void find_begin(){

    node *head = create_cir_list();
    display_cir_list(head);
    node *current = head;

    while(current->next > current)
        current = current->next;

    printf("Beginning Node is: No.%d, Data: %s", current->next->no, current->next->data);

}

#endif // FINDBEGIN_H_INCLUDED
