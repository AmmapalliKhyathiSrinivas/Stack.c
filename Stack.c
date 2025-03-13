#include <stdio.h>
#include <stdlib.h>

// Stack structure
struct Stack {
    int* arr;
    int top;
    int capacity;
};

// Function prototypes
void initStack(struct Stack* stack, int capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, int value);
int pop(struct Stack* stack);
int peek(struct Stack* stack);
int size(struct Stack* stack);
void printElements(struct Stack* stack);

int main() {
    struct Stack stack;
    int capacity;

    // Ask the user for the capacity of the stack
    printf("Enter the capacity of the stack: ");
    scanf("%d", &capacity);

    // Initialize the stack with the user-defined capacity
    initStack(&stack, capacity);

    int choice, value;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Size\n");
        printf("5. Is Empty\n");
        printf("6. Is Full\n");
        printf("7. Print Elements\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;
            case 3:
                value = peek(&stack);
                if (value != -1) {
                    printf("Top element: %d\n", value);
                }
                break;
            case 4:
                printf("Size of the stack: %d\n", size(&stack));
                break;
            case 5:
                if (isEmpty(&stack)) {
                    printf("Stack is empty.\n");
                } else {
                    printf("Stack is not empty.\n");
                }
                break;
            case 6:
                if (isFull(&stack)) {
                    printf("Stack is full.\n");
                } else {
                    printf("Stack is not full.\n");
                }
                break;
            case 7:
                printElements(&stack);
                break;
            case 8:
                printf("Exiting...\n");
                free(stack.arr); // Free dynamically allocated memory before exit
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function to initialize the stack with user-defined capacity
void initStack(struct Stack* stack, int capacity) {
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int*)malloc(capacity * sizeof(int)); // Dynamically allocate memory
    if (stack->arr == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
}

// Function to check if the stack is full
int isFull(struct Stack* stack) {
    return stack->top == stack->capacity - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow! Cannot push %d\n", value);
        return;
    }
    stack->arr[++stack->top] = value;
    printf("Pushed element: %d\n", value);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow! Stack is empty.\n");
        return -1;
    }
    int poppedValue = stack->arr[stack->top--];
    return poppedValue;
}

// Function to peek at the top element of the stack
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->arr[stack->top];
}

// Function to get the size of the stack
int size(struct Stack* stack) {
    return stack->top + 1;
}

// Function to print all the elements in the stack
void printElements(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}
