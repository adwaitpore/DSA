#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#define SIZE 50
char s[SIZE];
int top=-1;
push(char elem)
{
    s[++top]=elem;
}

char pop()
{
    return(s[top--]);
}

int pr(char elem)
{
    switch(elem)
    {
        case '#':return 0;
        case '(':return 1;
        case '+':
        case '-':return 2;
        case '*':
        case '/':return 3;
    }
}

void main()
{
    char inx[SIZE],posx[SIZE],ch,elem;
    int i=0,k=0;
    printf("Enter an infix expression\n");
    scanf("%s",inx);
    push('#');
    while((ch=inx[i++])!='\0')
    {
        if(ch=='(')
        push(ch);
        else if(isalnum(ch))posx[k++]=ch;
        else
        if((ch==')'))
        {
            while(s[top]!='(')
            posx[k++]=pop();
            elem=pop();
        }
        else
        {
            while(pr(s[top])>=pr(ch))
            posx[k++]=pop();
            push(ch);
        }
    }
    while(s[top]!='#')
    posx[k++]=pop();
    posx[k]='\0';
    printf("\nGiven Infix Expn: %s Postfix Expn: %s",inx,posx);
}