#include <stdio.h>
#include <string.h>

#define MAX 50

int push(char stack[MAX], char val, int *top);
char pop(char stack[MAX], int *top);
void rev_list(char list[MAX]);

int main() {
    char list[MAX];

    printf("Enter the list : ");
    scanf("%s", list);

    rev_list(list);

    printf("Reversed list : %s\n", list);

    return 0;
}

int push(char stack[MAX], char val, int *top) {
    if ((*top) == MAX - 1) {
        printf("Stack Full\n");
        return -1;
    } else {
        (*top)++;
        stack[*top] = val;
        return 0;
    }
}

char pop(char stack[MAX], int *top) {
    if ((*top) == -1) {
        printf("Stack Empty\n");
        return '\0'; 
    } else {
        char x = stack[*top];
        (*top)--;
        return x;
    }
}

void rev_list(char list[MAX]) {
    char stack[MAX];
    int top = -1, i = 0;

    while (list[i] != '\0') {
        push(stack, list[i], &top);
        i++;
    }

    i = 0;
    while (top != -1) {
        list[i] = pop(stack, &top);
        i++;
    }
    list[i] = '\0';
}
