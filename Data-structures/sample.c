#include <stdio.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue() {
    if (rear == MAX - 1) {
        printf("Queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;
        }

        printf("Enter element: ");
        scanf("%d", &queue[++rear]);
        printf("%d enqueued to the queue.\n", queue[rear]);
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
    } else {
        int deletedElement = queue[front];
        front++;

        if (front == rear) {
            front = rear = -1;
        }

        printf("%d dequeued from the queue.\n", deletedElement);
    }
}

void traversal() {
    if (front == -1) {
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;

    do {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Traversal\n");
        printf("4. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                traversal();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}
