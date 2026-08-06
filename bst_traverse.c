#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree bst;

struct binary_tree{
    int data;
    bst *left;
    bst *right;
};

bst *root_node=NULL;

void insert_bst(int data){
    bst *new_node = (bst*)malloc(sizeof(bst));
    new_node->data=data;
    new_node->left=NULL;
    new_node->right=NULL;
    
    if(root_node==NULL){
        printf("Tree is empty, Inserting ROOT\n");
        root_node=new_node;
        return;
    }
    
    bst *current_node=root_node;
    bst *parent_node=NULL;
    int left=0;
    while(current_node!=NULL){
        parent_node=current_node;
        if(data>current_node->data){
            printf("Right of %d\n", current_node->data);
            current_node=current_node->right;
            left=0;
        }
        else {
            printf("Left of %d\n", current_node->data);
            current_node=current_node->left;
            left=1;
        }
    }
    
    if(left) parent_node->left=new_node;
    else parent_node->right=new_node;
}

void preorder(bst *node){
    if(node==NULL) return;
    printf("%d  ", node->data);
    preorder(node->left);
    preorder(node->right);
    return;
}

void inorder(bst *node){
    if(node==NULL) return;
    inorder(node->left);
    printf("%d  ", node->data);
    inorder(node->right);
    return;
}

void postorder(bst *node){
    if(node==NULL) return;
    postorder(node->left);
    postorder(node->right);
    printf("%d  ", node->data);
    return;
}

int main()
{
    insert_bst(5);
    insert_bst(3);
    insert_bst(7);
    insert_bst(1);
    insert_bst(4);
    insert_bst(6);
    insert_bst(8);
    
    preorder(root_node); printf("\n");
    inorder(root_node); printf("\n");
    postorder(root_node); printf("\n");

    return 0;
}
