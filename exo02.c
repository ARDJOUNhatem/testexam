#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void reverse(Node** head) {
    Node* current = *head;
    Node* temp = NULL;

    while (current != NULL) {
        temp = getNext(current);
        setNext(current, current->prev);
        setPrev(current, temp);
        current = temp;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d <-> ", getValue(current));
        current = getNext(current);
    }
    printf("NULL\n");
}

int main() {
    Node* head = createNode(1);
    Node* second = createNode(2);
    Node* third = createNode(3);

    setNext(head, second);
    setPrev(second, head);
    setNext(second, third);
    setPrev(third, second);

    printf("Original List: ");
    printList(head);

    reverse(&head);

    printf("Reversed List: ");
    printList(head);

    return 0;
}