#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return head;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at end");
        printf("\n3. Print list");
        printf("\n4. Exit");
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
                printList(head);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
