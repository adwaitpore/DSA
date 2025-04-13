
#include <stdio.h>

#define SIZE 10  

struct Queue {
    int arr[SIZE], fr, re;
} queue;

void enqueue(int);
void dequeue();
void display();

void main() {
    queue.fr= -1;
    queue.re= -1;
    int ch, val;

    do {
        printf("\n1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit Program.\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (ch != 4);
}

void enqueue(int val) {
    if ((queue.re+ 1) % SIZE == queue.fr) {
        printf("Queue Full\n");
        return;
    }
    if (queue.fr == -1) {
        queue.fr = 0;
    }
    queue.re = (queue.re + 1) % SIZE;
    queue.arr[queue.re] = val;
    printf("%d ENQUEUED\n", val);
}

void dequeue() {
    if (queue.fr == -1) {
        printf("Queue Empty\n");
        return;
    }
    printf("Removed element: %d\n", queue.arr[queue.fr]);
    if (queue.fr== queue.re) {  
        queue.fr = queue.re = -1;  
        return;
    }
    queue.fr = (queue.fr + 1) % SIZE;
}

void display() {
    if (queue.fr == -1) {
        printf("Queue empty.\n");
        return;
    }

    printf("Queue Elements: ");
    int i = queue.fr;
    while (1) {
        printf("%d ", queue.arr[i]);
        if (i == queue.re) {
            printf("\n");
            return;
        }
        i = (i + 1) % SIZE;
    }
}