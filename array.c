#include <stdio.h>
#define MAX 10
int a[MAX];
int pt = -1;


void main()
{
    int ch,num,pos;
    do
    {
        printf("1.INSERT\n");
        printf("2.DELETE\n");
        printf("3.DISPLAY\n");
        printf("4.EXIT\n");
        printf("Enter your Choice : \n");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:printf("The Number to be inserted is \n");
                   scanf("%d", &num);
                   printf("Enter the position to insert the Number: \n");
                   scanf("%d", &pos);
                   ins(num,pos);
                   break;

            case 2:printf("Enter the Position of Number to  delete : \n");
                   scanf("%d", &pos);
                   del(pos);
                   break;

            case 3:display();
                   break;

            case 4:return;
                   break;

            default:printf("INVALID OPTION\n");
                    break;
        }
    } while (ch != 4);
}

void ins(int num,int pos)
{

    if (pt == MAX-1)
    {
        printf("NO SPACE IN ARRAY\n");
    }
    else
    {
        if (pos < 0 || pos > MAX-1)
        {
            printf("INVALID POSITION\n");
            return;
        }
        else
        {
            for (int i = MAX-1; i > pos; i--)
            {
                a[i] = a[i - 1];
            }
            a[pos] = num;
            pt++;
        }
    }
}

void del(int pos)
{

    if (pt == -1)
    {
        printf("EMPTY ARRAY\n");
    }
    else
    {
        if (a[pos] == 0)
        {
            printf("POSITION EMPTY\n");
        }
        else
        {
                printf("The deleted element is %d\n", a[pos]);
                a[pos] = 0;
                pt--;
        }
    }
}

void display()
{
    if (pt == -1)
    {
        printf("Array is empty.\n");
    }
    else
    {
        for (int i = 0; i < MAX; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
}
