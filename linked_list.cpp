#include<bits/stdc++.h>
using namespace std;

struct node {
    int value;
    node *next, *prev;
};

node *head, *tail;


void append(int value) {
    node *new_node= new node();
    new_node->value = value;


    if(head==NULL) {
        cout << "List is empty. Appending first value..." << endl;

        head = new_node;
        tail = new_node;
        return;
    }

    cout<< "Appending in last" << endl;
    tail->next = new_node;
    tail = new_node;
    return;
}


void append(int value1, int value2) {
    node *new_node= new node();
    new_node->value = value2;

    if(head==NULL) {
        append(value2);
        return;
    }

    node *current_node = head;

    while(current_node->value != value1) {

        if(current_node==tail) {
            cout<< value1 << " is not in list." << endl << "Appending in last..." << endl;
            current_node->next = new_node;
            new_node->prev = current_node;
            tail = new_node;
            return;
        }
        current_node = current_node->next;
    }

    cout<< value1 << " is found. " << "Appending after it..." << endl;

    if(current_node==head) {
        current_node->next=new_node;
        tail = new_node;
        return;
    }

    node *third_node = current_node->next;

    current_node->next = new_node;
    new_node->next = third_node;

    new_node->prev = current_node;
    third_node->prev = new_node;

    return;
}



void print_list() {
    node *current_node = head;

    if(current_node==NULL) {
        cout<< "List is empty. Exitting........." << endl;
        return;
    }

    cout << "List Items: ";

    while(true) {
        cout<< current_node->value << " ";
        if(current_node == tail) {
            cout<<endl;
            return;
        }

        current_node = current_node->next;
    }
}


int main() {

    print_list();

    append(2,1);

    print_list();

    append(1,2);

    print_list();

    append(3,4);

    print_list();

    append(2,3);

    print_list();
}