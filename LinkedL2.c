#include<stdio.h>
#include<stdlib.h>

typedef struct LinkedList LList;
struct LinkedList{
    int data;
    LList *next;
};

LList *head=NULL;

void ListInsert(int data){
    LList *node=(LList*)malloc(sizeof(LList));
    node->data=data;
    node->next=NULL;

    if(head==NULL){
        printf("List is empty, appending head\n");
        head=node;
        return;
    }

    LList *current_node=head;
    while(current_node->next!=NULL){
        current_node=current_node->next;
    }

    current_node->next=node;
    return;
}

void ListPrint(){
    LList *current_node=head;
    while(current_node!=NULL){
            printf("%d\n", current_node->data);
        current_node=current_node->next;
    }
}

int main(){
    ListInsert(5);
    ListInsert(15);
    ListInsert(20);

    ListPrint();
}
