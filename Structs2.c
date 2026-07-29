#include <stdio.h>
#include <stdlib.h>


struct LinkedL2{
    int data;
    struct LinkedL2 *next;
};

typedef struct LinkedL2 LinkedList;

void PUSH_END2(int data, LinkedList *head){
    LinkedList *node=(LinkedList*)malloc(sizeof(LinkedList));
    node->data=data;
    if(head==NULL){
        head=node;
    }
    else{
        LinkedList current_node=*head;
        while(current_node.next!=NULL){
            current_node=*current_node.next;
        }
        current_node.next=node;
    }
    return;
}

void printList(LinkedList head){
    LinkedList current_node=head;

    while(current_node!=NULL){
        printf("%d\n", current_node.data);
        current_node=*current_node.next;
    }
    return;
}

int main(){
    LinkedList head;
    printList(head);

    PUSH_END2(1,&head);
    printList(head);

    PUSH_END2(2,&head);
    PUSH_END2(3,&head);
    PUSH_END2(4,&head);

    printList(head);
    
}
