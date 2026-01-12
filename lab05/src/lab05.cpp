#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node* insertAtBeginning(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL)
        head->prev = newNode;

    return newNode;
}

Node* insertAtEnd(Node* head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        newNode->prev = NULL;
        return newNode;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

Node* deleteFromBeginning(Node* head) {
    if (head == NULL)
        return NULL;

    Node* temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete temp;
    return head;
}

Node* deleteFromEnd(Node* head) {
    if (head == NULL)
        return NULL;

    if (head->next == NULL) {
        delete head;
        return NULL;
    }

    Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    delete temp;
    return head;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Delete from beginning");
        printf("\n4. Delete from end");
        printf("\n5. Print list");
        printf("\n6. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 3:
                head = deleteFromBeginning(head);
                break;
            case 4:
                head = deleteFromEnd(head);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                return 0;
        }
    }
}
