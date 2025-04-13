#include <stdio.h>
#include <stdlib.h>
struct ll_node
{
    int data;
    struct ll_node *nt;
    struct ll_node *pr;
};
struct ll_node *help_ptr;

struct ll_node *insert(struct ll_node *list,int val);
struct ll_node *del(struct ll_node *list,int tar);
void display(struct ll_node *list);

void main()
{
    struct ll_node *myList;
    int ch,val;
    myList=NULL;
    do
    {
        printf("\nEnter the choice.\n");
        printf("1. Insert.\n");
        printf("2. Delete.\n");
        printf("3. Display.\n");
        printf("4. Exit program.\n");
        printf("Choose an option: ");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1: printf("\nEnter the value :");
                scanf("%d",&val);
                myList=insert(myList,val);
                break;
        case 2: printf("\nEnter the value to be deleted:");
                scanf("%d",&val);
                myList=del(myList,val);
                break;
        case 3: display(myList);
                break;
        case 4: printf("Exit Program");
                return;
        default:printf("Invalid option.\n");
        }
    } while (ch!=4);
}

struct ll_node *insert(struct ll_node *list,int val)
{
    struct ll_node *new, *help_ptr, *succ;
    new=(struct ll_node*)malloc(sizeof(struct ll_node));
    new->data=val;
    new->nt=NULL;
    new->pr=NULL;
    
    if(list==NULL || list->data>val)
    {
        new->nt=list;
        if(list!=NULL)
            list->pr=new;
        list=new;
        return list;
    }
    help_ptr=list;
    
    while(help_ptr->nt!=NULL && help_ptr->nt->data<val)
        help_ptr=help_ptr->nt;
    
    succ=help_ptr->nt;
    help_ptr->nt=new;
    new->pr=help_ptr;
    new->nt=succ;
    if(succ!=NULL)
        succ->pr=new;
    return list;
}

struct ll_node *del(struct ll_node *list,int tar)
{
    struct ll_node *help_ptr, *node2delete;
    help_ptr = list;
    if (help_ptr != NULL)
    {
        if (help_ptr->data == tar)
        {
            list = help_ptr->nt;
            help_ptr->nt->pr=NULL;
            free(help_ptr);
            return list;
        }
        while (help_ptr->nt!=NULL)
        {
            if (help_ptr->nt->data == tar)
            {
                node2delete = help_ptr->nt;
                help_ptr->nt = node2delete->nt;
                if(node2delete->nt!=NULL)
                    node2delete->nt->pr=help_ptr;
                free(node2delete);
                return list;
            }
            help_ptr = help_ptr->nt;
        }
        printf("Element not found.");
        return list;
    }
    printf("List empty.");
    return list;
}

void display(struct ll_node *list)
{
    struct ll_node *help_ptr;
    help_ptr=list;
    printf("\n");
    while(help_ptr!=NULL)
    {
        printf("%d->",help_ptr->data);
        help_ptr=help_ptr->nt;
    }
}
