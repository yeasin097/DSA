#include<stdio.h>
#include<stdlib.h>

typedef struct LList List;

struct LList {
    int data;
    List *next;
};

void inList(int data, List **head){
    List *node=(List *)malloc(sizeof(List));
    node->data=data;
    node->next=NULL;

    if(*head==NULL){
        *head=node;
        return;
    }
    List *current_node=*head;
    while(current_node->next!=NULL){
            current_node=current_node->next;
    }
    current_node->next=node;
}

void PrintList(List *head){
    if(head==NULL){
        printf("The list is empty\n");
        return;
    }
    List *current_node=head;
    while(current_node!=NULL){
            printf("%d\n", current_node->data);
            current_node=current_node->next;
    }
    return;
}

void changeInt(int *x){
    *x=10;
    return;
}


int main(){
    List *head=NULL;
    PrintList(head);
    inList(5, &head);
    PrintList(head);

    int x=5;
    changeInt(&x);
    printf("%d\n", x);

}
