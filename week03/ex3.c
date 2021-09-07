#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

void print_list(struct node *head) {
    head = head->next;
    
    while (head != NULL) {
        printf("%d\n", head->val);
        head = head->next;
    }
}

void insert_node(struct node *head, struct node *newnode, struct node *prevnode) {
    while (head != prevnode) {
        head = head->next;
    }
    
    newnode->next = head->next;
    head->next = newnode;
}

void delete_node(struct node *head, struct node *delnode) {
    while (head->next != delnode) {
        head = head->next;
    }
    
    struct node* ondelete = head->next;
    head->next = ondelete->next;
    free(ondelete);
}

int main() {
    // For the semplicity of implementation, head 
    // is not considered to store a value. It just
    // represents the beginning of the list
    
    struct node* head = malloc(sizeof(struct node));
    
    // Generating a list
    for (int i = 0; i < 10; i++) {
        struct node* newnode = malloc(sizeof(struct node));
        newnode->val = rand() % 20;
        
        insert_node(head, newnode, head);
    }
    
    printf("Initial structure:\n");
    print_list(head);
    
    // Inserting a node
    struct node* newnode = malloc(sizeof(struct node));
    newnode->val = rand() % 20;
    
    struct node* temp = head;
    for (int i = 0; i < 5; i++) {
        temp = temp->next;
    }
    insert_node(head, newnode, temp);
    
    printf("Insert a node with value %d after node5:\n", temp->next->val);
    print_list(head);
    
    // Removing the node
    delete_node(head, newnode);
    
    printf("Delete the node after node5:\n");
    print_list(head);
    
    return 0;
}
