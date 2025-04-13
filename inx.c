#include <stdio.h>
#include <ctype.h>

#define SIZE 50

char s[SIZE];
int top = -1;

void push(char elem) {
    if (top < SIZE - 1)
        s[++top] = elem;
    else
        printf("Stack Overflow\n");
}

char pop() {
    if (top >= 0)
        return s[top--];
    else {
        printf("Stack Underflow\n");
        return '#';  // Return a default value in case of underflow
    }
}

int precedence(char elem) {
    switch (elem) {
        case '#': return 0;
        case '(': return 1;
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 3;
        default: return -1;  // If an invalid character is given
    }
}

int main() {
    char inx[SIZE], posx[SIZE], ch, elem;
    int i = 0, k = 0;

    printf("Enter an infix expression: ");
    scanf("%49s", inx);  // Prevent buffer overflow

    push('#');

    while ((ch = inx[i++]) != '\0') {
        if (ch == '(') {
            push(ch);
        } else if (isalnum(ch)) {  // If operand, add to postfix
            posx[k++] = ch;
        } else if (ch == ')') {  // If closing parenthesis, pop till '('
            while (s[top] != '(')
                posx[k++] = pop();
            pop();  // Remove '('
        } else {  // Operator
            while (precedence(s[top]) >= precedence(ch))
                posx[k++] = pop();
            push(ch);
        }
    }

    while (s[top] != '#')  // Pop remaining operators
        posx[k++] = pop();

    posx[k] = '\0';  // Null terminate postfix expression

    printf("\nGiven Infix Expression: %s\nPostfix Expression: %s\n", inx, posx);

    return 0;
}
