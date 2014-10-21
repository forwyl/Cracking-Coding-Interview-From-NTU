#ifndef LINKEDLISTUTIL_H_INCLUDED
#define LINKEDLISTUTIL_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define LEN 20

int siz;
typedef struct node{

    int no;
    char data[LEN];
    struct node *next;

}node;

node* input_list(){

    int no = 1;
    int i = 0;
    char data[LEN];

    node *head = NULL;
    node *current = NULL;
    node *previous = NULL;

    printf("Set list size:");
    scanf("%d", &siz);
    while(siz==0 || i<siz){
        printf("Set data(string):");
        scanf("%s", &data);

        current = (struct node*)malloc(sizeof(struct node));
        if(current==NULL)
            exit(EXIT_FAILURE);

        current->next = NULL;
        current->no = no++;
        strncpy(current->data, data, LEN-1);
        current->data[LEN-1] = '\0';

        if(head==NULL)
            head = current;
        else
            previous->next = current;

        previous = current;
        i++;
    }

    return head;

}

void display_list(node *head){

    node *current = head;
    printf("-------------[Show LinkedList]-------------\n");
    while(current != NULL){
        printf("No. = %d, Data = %s \n", current->no,  current->data);
        current = current->next;
    }

}

void free_list(node *head){

    node *current = NULL;
    node *previous = NULL;
    current = head;
    while(current != NULL){
        previous = current;
        current = current->next;
        free(previous);
    }

}

int count_size(node *head){

    int list_siz = 0;
    node *current = NULL;

    current = head;
    while(current != NULL){
        current = current->next;
        list_siz++;
    }

    return list_siz;

}

node* clone_node(node *current){

    char data[LEN];

    int no = current->no;
    strncpy(data, current->data, sizeof(data)-1);
    data[sizeof(data)-1] = '\0';
    current = (struct node*)malloc(sizeof(struct node));
    current->next = NULL;
    current->no = no;
    strncpy(current->data, data, sizeof(data)-1);
    current->data[sizeof(data)-1] = '\0';

    return current;
}

node* find_Nth(node *head, int index){

    node *current;

    current = head;
    while(index > 1){
        current = current->next;
        index--;
    }

    return current;

}

node* reverse_list(node *head){

    node *p, *q, *r, *temp;
    p = NULL;
    q = head;
    r = head->next;
    while(q != NULL){
        temp = q;
        q->next = p;
        p = temp;
        q = r;
        if(r != NULL)
            r = r->next;
    }
    head = p;

    return head;
}

node* create_cir_list(){

    int no = 1;
    int i = 0;
    char data[LEN];

    node *head = NULL;
    node *current = NULL;
    node *previous = NULL;

    printf("Set circular list size:");
    scanf("%d", &siz);
    while(siz==0 || i<siz){
        printf("Set data(string):");
        scanf("%s", &data);

        current = (struct node*)malloc(sizeof(struct node));
        if(current==NULL)
            exit(EXIT_FAILURE);

        if(i<siz-1){
            current->next = NULL;
        }else{
            current->next = head;
        }
        current->no = no++;
        strncpy(current->data, data, LEN-1);
        current->data[LEN-1] = '\0';

        if(head==NULL)
            head = current;
        else
            previous->next = current;

        previous = current;
        i++;
    }

    return head;

}

void display_cir_list(node *head){

    int flag = 0;
    node *current = head;
    printf("-------------[Show Circular LinkedList]-------------\n");

    while(flag < 2){
        if(current==head){
            flag++;
        }
        printf("No. = %d, Data = %s \n", current->no,  current->data);
        current = current->next;
    }

}

#endif // LINKEDLISTUTIL_H_INCLUDED
