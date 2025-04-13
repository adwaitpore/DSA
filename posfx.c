#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 50


struct Stack {
    int top;
    int array[MAX];
};


void push(struct Stack* st, int val) {
    if (st->top == MAX - 1) {
        printf("STACK FULL\n");
        return;
    }
    st->array[++st->top] = val;
}

int pop(struct Stack* st) {
    if (st->top == -1) {
        printf("STACK EMPTY\n");
        return -1;
    }
    return st->array[st->top--];
}


int evalPostfix(char* exp) {
    struct Stack st;
    st.top = -1;


    for (int i = 0; exp[i]; i++) {

        if (isdigit(exp[i])) {
            push(&st, exp[i] - '0');
        }

        else {
            int val1 = pop(&st);
            int val2 = pop(&st);

            switch (exp[i]) {
                case '+': push(&st, val2 + val1); break;
                case '-': push(&st, val2 - val1); break;
                case '*': push(&st, val2 * val1); break;
                case '/': 
                    if (val1 == 0) {
                        printf("DIVISION BY ZERO!\n");
                        return -1;
                    }
                    push(&st, val2 / val1); 
                    break;
                default:
                    printf("INVALID OPERATOR: %c\n", exp[i]);
                    return -1;
            }
        }
    }
    return pop(&st);
}



int main() {
    
    printf("Enter a postfix Expression: ");
    char exp[10];
    scanf("%s",exp);
    printf("Postfix Evaluation Result: %d\n", evalPostfix(exp));
    return 0;
}

