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
    return newNode;
}

struct Node* insertBefore(struct Node* head, int target, int value) {
    if (head == NULL) return head;

    struct Node* newNode = new Node;
    newNode->data = value;

    if (head->data == target) {
        newNode->next = head;
        return newNode;
    }

    struct Node* prev = head;
    struct Node* curr = head->next;

    while (curr != NULL && curr->data != target) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != NULL) {
        newNode->next = curr;
        prev->next = newNode;
    } else {
        delete newNode;
        printf("Target element not found.\n");
    }

    return head;
}

struct Node* deleteBefore(struct Node* head, int target) {
    if (head == NULL || head->next == NULL || head->data == target) {
        printf("No element exists before %d.\n", target);
        return head;
    }

    struct Node* prevPrev = NULL;
    struct Node* prev = head;
    struct Node* curr = head->next;

    while (curr != NULL && curr->data != target) {
        prevPrev = prev;
        prev = curr;
        curr = curr->next;
    }

    if (curr == NULL) {
        printf("Target element not found.\n");
    } else {
        if (prevPrev == NULL) {
            head = curr;
            delete prev;
        } else {
            prevPrev->next = curr;
            delete prev;
        }
    }

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
    int choice, value, target;

    while (1) {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert before element");
        printf("\n3. Delete before element");
        printf("\n4. Print list");
        printf("\n5. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                scanf("%d", &target);
                scanf("%d", &value);
                head = insertBefore(head, target, value);
                break;
            case 3:
                scanf("%d", &target);
                head = deleteBefore(head, target);
                break;
            case 4:
                printList(head);
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
