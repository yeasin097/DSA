#include <stdio.h>
#include <stdlib.h>

struct LinkedL {
    int data;
    struct LinkedL *next;
};



void PUSH_END(int data, struct LinkedL **head) {
    struct LinkedL *node = (struct LinkedL *)malloc(sizeof(struct LinkedL));
    node->data = data;
    node->next = NULL;

    // Empty list
    if (*head == NULL) {
        *head = node;
        return;
    }

    struct LinkedL *current_node = *head;

    while (current_node->next != NULL) {
        current_node = current_node->next;
    }

    current_node->next = node;
}

void PRINT_LL(struct LinkedL *head) {
    if (head == NULL) {
        printf("EMPTY\n");
        return;
    }

    struct LinkedL *current_node = head;

    while (current_node != NULL) {
        printf("%d -> ", current_node->data);
        current_node = current_node->next;
    }

    printf("END\n");
}

int main(void) {
    struct LinkedL *head_link = NULL;

    PUSH_END(10, &head_link);
    PUSH_END(20, &head_link);
    PUSH_END(30, &head_link);
    PUSH_END(40, &head_link);

    PRINT_LL(head_link);

    return 0;
}