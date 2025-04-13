#include <stdio.h>
#include <stdlib.h>

struct ll_node {
    int data;
    struct ll_node *next;
};


struct ll_node* addToFront(struct ll_node *list, int val) {
    struct ll_node *New = (struct ll_node*) malloc(sizeof(struct ll_node));
    if (!New) {
        printf("Memory allocation failed\n");
        return list;
    }
    New->data = val;
    New->next = list;
    return New;
}


struct ll_node* addToEnd(struct ll_node *list, int val) {
    struct ll_node *New = (struct ll_node*) malloc(sizeof(struct ll_node));
    if (!New) {
        printf("Memory allocation failed\n");
        return list;
    }
    New->data = val;
    New->next = NULL;

    if (list == NULL) {
        return New;
    }

    struct ll_node *help_ptr = list;
    while (help_ptr->next != NULL) {
        help_ptr = help_ptr->next;
    }
    help_ptr->next = New;
    
    return list;
}


struct ll_node* insertSorted(struct ll_node *list, int val) {
    struct ll_node *New = (struct ll_node*) malloc(sizeof(struct ll_node));
    if (!New) {
        printf("Memory allocation failed\n");
        return list;
    }
    New->data = val;
    New->next = NULL;

    if (list == NULL || list->data > val) {
        New->next = list;
        return New;
    }

    struct ll_node *help_ptr = list;
    while (help_ptr->next != NULL && help_ptr->next->data < val) {
        help_ptr = help_ptr->next;
    }

    New->next = help_ptr->next;
    help_ptr->next = New;
    
    return list;
}


struct ll_node* deleteNode(struct ll_node *list, int tar) {
    struct ll_node *help_ptr = list, *nodedel;

    if (help_ptr == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }

    if (help_ptr->data == tar) {
        list = help_ptr->next;
        free(help_ptr);
        printf("Deleted %d from the list.\n", tar);
        return list;
    }

    while (help_ptr->next != NULL) {
        if (help_ptr->next->data == tar) {
            nodedel = help_ptr->next;
            help_ptr->next = help_ptr->next->next;
            free(nodedel);
            printf("Deleted %d from the list.\n", tar);
            return list;
        }
        help_ptr = help_ptr->next;
    }

    printf("Element %d not found in the list.\n", tar);
    return list;
}


void printList(struct ll_node *list) {
    if (list == NULL) {
        printf("The list is empty.\n");
        return;
    }
    printf("Linked List: ");
    while (list != NULL) {
        printf("%d -> ", list->data);
        list = list->next;
    }
    printf("NULL\n");
}


void freeList(struct ll_node *list) {
    struct ll_node *tp;
    while (list != NULL) {
        tp = list;
        list = list->next;
        free(tp);
    }
}


int main() {
    struct ll_node *head = NULL;
    int ch, val;

    while (1) {
        printf("\nMENU:\n");
        printf("1. Insert at Front\n");
        printf("2. Insert at End\n");
        printf("3. Insert in Sorted Order\n");
        printf("4. Delete a Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &val);
                head = addToFront(head, val);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &val);
                head = addToEnd(head, val);
                break;
            case 3:
                printf("Enter value to insert in sorted order: ");
                scanf("%d", &val);
                head = insertSorted(head, val);
                break;
            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                head = deleteNode(head, val);
                break;
            case 5:
                printList(head);
                break;
            case 6:
                freeList(head);
                printf("Exit Program.\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
