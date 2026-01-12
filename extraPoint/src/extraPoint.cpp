#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    char data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void push(struct Stack* stack, char value) {
    struct Node* newNode = new Node;
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(struct Stack* stack) {
    if (stack->top == NULL) return '\0';
    struct Node* temp = stack->top;
    char val = temp->data;
    stack->top = temp->next;
    delete temp;
    return val;
}

char peek(struct Stack* stack) {
    if (stack->top == NULL) return '\0';
    return stack->top->data;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPostfix(char* exp) {
    struct Stack stack;
    stack.top = NULL;
    char postfix[100];
    int k = 0;

    for (int i = 0; exp[i]; i++) {
        char c = exp[i];
        if (isalnum(c)) {  
            postfix[k++] = c;
        } else if (c == '(') {
            push(&stack, c);
        } else if (c == ')') {
            while (!isEmpty(&stack) && peek(&stack) != '(')
                postfix[k++] = pop(&stack);
            pop(&stack); 
        } else { 
            while (!isEmpty(&stack) && precedence(peek(&stack)) >= precedence(c))
                postfix[k++] = pop(&stack);
            push(&stack, c);
        }
    }

    while (!isEmpty(&stack))
        postfix[k++] = pop(&stack);

    postfix[k] = '\0';
    printf("Postfix: %s\n", postfix);
}

int evaluatePostfix(char* exp) {
    struct Node* stack = NULL;

    for (int i = 0; exp[i]; i++) {
        char c = exp[i];
        if (isdigit(c)) {
            struct Node* newNode = new Node;
            newNode->data = c - '0';
            newNode->next = stack;
            stack = newNode;
        } else { 
            int b = stack->data;
            struct Node* temp = stack;
            stack = stack->next;
            delete temp;

            int a = stack->data;
            temp = stack;
            stack = stack->next;
            delete temp;

            int res;
            if (c == '+') res = a + b;
            if (c == '-') res = a - b;
            if (c == '*') res = a * b;
            if (c == '/') res = a / b;

            struct Node* newNode = new Node;
            newNode->data = res;
            newNode->next = stack;
            stack = newNode;
        }
    }
    int result = stack->data;
    delete stack;
    return result;
}

int main() {
    int choice;
    char exp[100];

    while (1) {
        printf("\n1. Convert infix to postfix");
        printf("\n2. Evaluate postfix expression");
        printf("\n3. Exit");
        printf("\nChoice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter infix expression (e.g., a+b*c): ");
                scanf("%s", exp);
                infixToPostfix(exp);
                break;
            case 2:
                printf("Enter postfix expression (digits only, e.g., 7 2 3 * +): ");
                scanf("%s", exp);
                printf("Result: %d\n", evaluatePostfix(exp));
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
