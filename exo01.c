#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", getValue(current)); 
        current = getNext(current); 
    }
    printf("NULL\n"); 
}


int getListSize(Node* head) {
    int size = 0;
    Node* current = head;
    while (current != NULL) {
        size++; 
        current = getNext(current); 
    }
    return size; 
}


Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = createNode(value); 
    if (newNode == NULL) {
        printf("Failed to allocate memory for new node.\n");
        return head; 
    }

    
    if (position == 0) {
        setNext(newNode, head); 
        return newNode; 
    }

    Node* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = getNext(current); 
    }

    if (current != NULL) {
        setNext(newNode, getNext(current));
        setNext(current, newNode);
    } else {
        printf("Position out of bounds.\n");
        deleteNode(newNode); 
    }

    return head; 
}

int main() {
    Node* head = NULL;

    head = insertAtPosition(head, 0, 0);
    printf("After inserting 0 at the beginning:\n");
    printList(head);

    
    int middlePosition = getListSize(head) / 2;
    head = insertAtPosition(head, 0, middlePosition);
    printf("After inserting 0 in the middle:\n");
    printList(head);

    
    int endPosition = getListSize(head);
    head = insertAtPosition(head, 0, endPosition);
    printf("After inserting 0 at the end:\n");
    printList(head);

    
    Node* current = head;
    while (current != NULL) {
        Node* next = getNext(current);
        deleteNode(current);
        current = next; 
    }

    return 0; 
}