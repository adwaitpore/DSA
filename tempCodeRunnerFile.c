#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100
struct Stack
{
    char stack[MAX];
    int top; 
}s; 
int push(char sym) 
{
    if (s.top == MAX-1)
    {
        printf("STACK FULL\n"); 
        return 0; 
    }
    s.stack[s.top] = sym; 
    s.top++; 
    return 1;
}
char pop() 
{ 
    if (s.top == 0) 
    { 
        printf("STACK EMPTY\n"); 
        return 0; 
    } 
    s.top--; 
    return s.stack[s.top]; 
} 
int precedence(char chr) 
{ 
    switch (chr) 
    { 
        case '+': 
        case '-': return 1; 
        case '*': 
        case '/': return 2; 
        case '^': return 3; 
        default: return 0; 
    } 
} 
int main() 
{ 
    s.top = 0; 
    char in_str[MAX]; 
    char pos_str[MAX]; 
    int pos_ind = 0;
    printf("Enter the Infix String: "); 
    scanf("%s", in_str); 
    for(int i = 0; i < strlen(in_str); i++) 
    { if (isalnum(in_str[i]))
        { 
            pos_str[pos_ind++] = in_str[i]; 
        } 
        else if (in_str[i] == '(')
        {
            push(in_str[i]); 
        } 
        else if (in_str[i] == ')')
        {
            while (s.top > 0 && s.stack[s.top- 1] != '(') 
            { 
                pos_str[pos_ind++] = pop(); 
            } pop(); 
        }
        else  
        { 
            while (s.top > 0 && precedence(in_str[i]) <= precedence(s.stack[s.top- 1])) 
            { 
                pos_str[pos_ind++] = pop(); 
            } 
            push(in_str[i]); 
        } 
    }  
    while(s.top>0) 
    { 
        pos_str[pos_ind++]=pop(); 
    } 
    pos_str[pos_ind]='\0'; 
    printf("PostfixExpression:%s\n",pos_str);
    return 0; 
} 