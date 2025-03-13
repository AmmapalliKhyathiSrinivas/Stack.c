/*
 * Stack Implementation in C
 * Features:
 * 1. Push operation
 * 2. Pop operation
 * 3. Peek (Top element)
 * 4. Check if stack is empty
 * 5. Check if stack is full
 * 6. Get stack size
 * 7. Print all elements
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

// Stack structure
typedef struct {
    int top;
    int array[MAX];
} Stack;

// Function to initialize the stack
void initStack(Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Function to check if the stack is full
bool isFull(Stack *stack) {
    return stack->top == MAX - 1;
}

// Function to push an element onto the stack
void push(Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack is full!\n");
        return;
    }
    stack->array[++stack->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to get the top element (peek)
int peek(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return -1;
    }
    return stack->array[stack->top];
}

// Function to get the size of the stack
int size(Stack *stack) {
    return stack->top + 1;
}

// Function to print the elements of the stack
void printStack(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printStack(&stack);
    
    printf("Top element: %d\n", peek(&stack));
    printf("Stack size: %d\n", size(&stack));

    printf("Popped element: %d\n", pop(&stack));
    printStack(&stack);
    
    return 0;
}


#Output
/* Pushed 10 onto the stack.
Pushed 20 onto the stack.
Pushed 30 onto the stack.
Stack elements: 10 20 30 
Top element: 30
Stack size: 3
Popped element: 30
Stack elements: 10 20 */
