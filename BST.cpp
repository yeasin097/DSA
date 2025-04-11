#include<bits/stdc++.h>
using namespace std;

struct node {
    int value;
    node *left, *right;
};

node *root;

void append(int value) {

    node *new_node = new node();
    new_node->value = value;
    if(root==NULL) {
        root = new_node;
        return;
    }

    node *current_node = root;
    node *previous_node;

    while(current_node != NULL) {
        previous_node = current_node;
        if(current_node->value > value) {
            current_node = current_node->left;
        }
        else {
            current_node = current_node->right;
        }
        
    }

    if(previous_node->value > value) {
        previous_node->left = new_node;
    }
    else {
        previous_node->right = new_node;
    }
    return;

    return;
}

void pre_traverse(node *current_node) {
    if(current_node==NULL) {
        return;
    }

    cout << current_node->value << endl;
    pre_traverse(current_node->left);
    pre_traverse(current_node->right);
}

int main() {
    append(5);
    append(3);
    append(4);
    append(8);
    append(6);
    append(7);
    append(1);
    pre_traverse(root);

    //cout<< root->left->value << endl;
}