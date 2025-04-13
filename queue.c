#include<stdio.h>
#define MAX 5

struct Queue
{
    int a[MAX];
    int front,rear;
}q1;

void enqueue(int val)
{
    if(q1.rear==MAX-1)
    {
       printf("QUEUE FULL\n");
       return;
    }
    else
    {
        if(q1.front==-1)
        {
            q1.front=0;
        }
        q1.rear+=1;
        q1.a[q1.rear]=val;
    }
}

void dequeue()
{
    if(q1.front==-1 || q1.front >q1.rear)
    {
       printf("QUEUE EMPTY\n");
       return;
    }
    printf("Dequeue element is %d\n",q1.a[q1.front]);
    for(int i=0;i<q1.rear;i++)
    {
       q1.a[i]=q1.a[i+1];
    }
    q1.rear--;
}
void display()
{
    if(q1.rear==-1)
    {
        printf("QUEUE EMPTY\n");
        return;
    }
    for(int i=0;i<=q1.rear;i++)
    {
        printf("%d ",q1.a[i]);
    }
}
void main()
{
    int ch,val;
    q1.front=-1;
    q1.rear=-1;
    do
    {
        printf("1.ENQUEUE\n");
        printf("2.DEQUEUE\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the number");
                   scanf("%d",&val);
                   enqueue(val);
                   break;
            case 2:dequeue();
                   break;
            case 3:display();
                   break;
            case 4:return;
                   break;
            default:printf("Invalid choice\n");
                    break;
        }
    } while(ch!=4);
    return 0;
}