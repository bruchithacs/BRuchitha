#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}



void push(struct Node **top, int data) {
    struct Node *newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d\n", data);
}


void pop(struct Node **top) {
    if (*top == NULL) {
        printf("Stack Underflow!\n");
        return;
    }
    struct Node *temp = *top;
    *top = (*top)->next;
    printf("Popped %d\n", temp->data);
    free(temp);
}


void displayStack(struct Node *top) {
    if (top == NULL) {
        printf("Stack is Empty\n");
        return;
    }
    while (top != NULL) {
        printf("%d -> ", top->data);
        top = top->next;
    }
    printf("NULL\n");
}


void enqueue(struct Node **front, struct Node **rear, int data) {
    struct Node *newNode = createNode(data);
    if (*rear == NULL) {
        *front = *rear = newNode;
        return;
    }
    (*rear)->next = newNode;
    *rear = newNode;
    printf("Enqueued %d\n", data);
}

void dequeue(struct Node **front, struct Node **rear) {
    if (*front == NULL) {
        printf("Queue Underflow!\n");
        return;
    }
    struct Node *temp = *front;
    printf("Dequeued %d\n", temp->data);
    *front = (*front)->next;

    if (*front == NULL)
        *rear = NULL;

    free(temp);
}


void displayQueue(struct Node *front) {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return;
    }
    while (front != NULL) {
        printf("%d -> ", front->data);
        front = front->next;
    }
    printf("NULL\n");
}


int main() {
    struct Node *stackTop = NULL;
    struct Node *front = NULL, *rear = NULL;

    int choice, value;

    while (1) {
        printf("\n------ MENU ------\n");
        printf("1. Push (Stack)\n");
        printf("2. Pop (Stack)\n");
        printf("3. Display Stack\n");
        printf("4. Enqueue (Queue)\n");
        printf("5. Dequeue (Queue)\n");
        printf("6. Display Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push(&stackTop, value);
                break;

            case 2:
                pop(&stackTop);
                break;

            case 3:
                displayStack(stackTop);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(&front, &rear, value);
                break;

            case 5:
                dequeue(&front, &rear);
                break;

            case 6:
                displayQueue(front);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }
    return 0;
}
