#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define SIZE 50


struct Stack {
    int top;
    int array[SIZE];
};
struct Stack S1;

int pop() {
    if (S1.top != -1)
        return S1.array[S1.top--];
    return -1; 
}

void push(int op) {
    S1.array[++S1.top] = op;
}


int evaluatePostfix(char* exp) {
    S1.top = -1;
    for (int i = 0; exp[i]; ++i) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0'); 
        } else {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
                default: printf("Invalid character in expression\n"); return -1;
            }
        }
    }
    return pop();
}

int main() {
    char exp[SIZE];
    printf("Enter a postfix expression: ");
    scanf("%s", exp);
    printf("Postfix evaluation: %d\n", evaluatePostfix(exp));
    return 0;
}
