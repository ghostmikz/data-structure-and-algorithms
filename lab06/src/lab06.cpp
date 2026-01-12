#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* push(struct Node* top, int value) {
    struct Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    return top;
}

struct Node* pop(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return top;
    }

    struct Node* temp = top;
    top = top->next;
    delete temp;
    return top;
}

void printStack(struct Node* top) {
    struct Node* temp = top;
    printf("Stack (top -> bottom): ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* top = NULL;
    int choice, value;

    while (1) {
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Print stack");
        printf("\n4. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &value);
                top = push(top, value);
                printStack(top);
                break;
            case 2:
                top = pop(top);
                printStack(top);
                break;
            case 3:
                printStack(top);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
