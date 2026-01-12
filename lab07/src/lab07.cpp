#include <stdio.h>
#include <stdlib.h>

struct Node {
    char data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

struct Node* enqueue(struct Node* rear, char value) {
    struct Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return rear;
    }

    rear->next = newNode;
    rear = newNode;
    return rear;
}

struct Node* dequeue(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return front;
    }

    struct Node* temp = front;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    delete temp;
    return front;
}

void print_queue() {
    struct Node* temp = front;
    printf("Queue (front -> rear): ");
    while (temp != NULL) {
        printf("%c ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int choice;
    char value;

    while (1) {
        printf("\n1. Enqueue");
        printf("\n2. Dequeue");
        printf("\n3. Print Queue");
        printf("\n4. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf(" %c", &value);
                rear = enqueue(rear, value);
                print_queue();
                break;
            case 2:
                front = dequeue(front);
                print_queue();
                break;
            case 3:
                print_queue();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
