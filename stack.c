#include<stdio.h>
#define MAX 5

struct Stack
{
    int a[MAX];
    int top;
}s1;

void push(int val)
{
    if(s1.top!=MAX-1)
    {
    s1.top++;
    s1.a[s1.top]=val;
    return;
    }
    else
    printf("Stack is full\n");
}
void pop()
{
    int element;
    if(s1.top==-1)
    {
        printf("\n Stack is empty");
        return;
    }
    element=s1.a[s1.top];
    printf("\n The deleted element is %d\n", element);
    s1.top--;
}
void display()
{
    if(s1.top==-1)
    {
        printf("\nStack is empty");
        return;
    }
    for(int i=s1.top;i>-1;i--)
    {
        printf("\n %d", s1.a[i]);
    }
    return;
}
void main()
{   
    int ch;
    int val;
    do
    {
    printf("1.PUSH\n");
    printf("2.POP\n");
    printf("3.DISPLAY\n");
    printf("4.EXIT\n");
    printf("Enter your choice\n");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:printf("Enter a number\n");
               scanf("%d",&val);
               push(val);
               break;
        case 2:pop();
               break;
        case 3:display();
               break;
        case 4: return;
               break;
        default:printf("Invalid choice\n");
    }
    }while(ch!=4);
    return 0;
}