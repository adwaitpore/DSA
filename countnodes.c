#include <stdio.h>
#include <stdlib.h>

struct ll_node {
    int data;
    struct ll_node *next;
};

struct ll_node *front = NULL, *rear = NULL;

struct ll_node *enqueuerear(struct ll_node *list, int value);
struct ll_node *dequeuefront(struct ll_node *list);
struct ll_node *enqueuefront(struct ll_node *list, int value);
struct ll_node *dequeuerear();
void display(struct ll_node *list);

struct ll_node *enqueuerear(struct ll_node *list, int value) {
    struct ll_node *pnew = (struct ll_node *)malloc(sizeof(struct ll_node));
    pnew->data = value;
    pnew->next = NULL;

    if (front == NULL) {
        front = pnew;
        list = pnew;
        return list;
    }

    list->next = pnew;
    return list;
}

struct ll_node *enqueuefront(struct ll_node *list, int value) {
    struct ll_node *pnew = (struct ll_node *)malloc(sizeof(struct ll_node));
    pnew->data = value;
    pnew->next = NULL;

    if (front == NULL) {
        front = pnew;
        list = pnew;
        return list;
    }

    pnew->next = list;
    list = pnew;
    return list;
}

struct ll_node *dequeuefront(struct ll_node *list) {
    if (front != NULL) {
        struct ll_node *node2delete = list;
        list = list->next;
        free(node2delete);
        return list;
    }
    printf("Queue empty\n");
    return list;
}

struct ll_node *dequeuerear() {
    struct ll_node *hp = front;
    if (hp == NULL) {
        printf("Queue empty\n");
        return rear;
    }
    while (hp->next->next != NULL) {
        hp = hp->next;
    }
    free(hp->next);
    hp->next = NULL;
    return front;
}

void display(struct ll_node *list) {
    struct ll_node *help_ptr;
    help_ptr = list;
    printf("\n");
    if (help_ptr == NULL)
        printf("Queue empty");
    while (help_ptr != NULL) {
        printf("%d\n", help_ptr->data);
        help_ptr = help_ptr->next;
    }
}

int main() {
    int choice, value;
    while (1) {
        printf("1. Enqueue from rear.\n");
        printf("2. Dequeue from front.\n");
        printf("3. Enqueue from front.\n");
        printf("4. Dequeue from rear.\n");
        printf("5. Display.\n");
        printf("6. Exit program.\n");
        printf("Choose an option: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the value to be enqueued: ");
                scanf("%d", &value);
                rear = enqueuerear(rear, value);
                break;
            case 2:
                front = dequeuefront(front);
                break;
            case 3:
                printf("\nEnter the value to be enqueued from front: ");
                scanf("%d", &value);
                front = enqueuefront(front, value);
                break;
            case 4:
                rear = dequeuerear();
                break;
            case 5:
                display(front);
                break;
            case 6:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}