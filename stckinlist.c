#include<stdio.h>
#include<stdlib.h>
struct tree_node
{
   int data;
   struct tree_node *left;
   struct tree_node *right;
};
typedef struct tree_node tn;
//tn *root=NULL;
/*struct node *insert(struct node *root,int val)
{
    tn *prev=NULL,*hp=NULL;
    tn *tnew=(tn*)malloc(sizeof(tn));
    tnew->data=val;
    tnew->left=NULL;
    tnew->right=NULL;
    if(root==NULL)
    {
        root=tnew;
        return root;
    }
    hp=root;
    while(hp!=NULL)
    {
        if(hp->data >val)
        {
            prev=hp;
            hp=hp->left;
        }
        else
        {
            prev=hp;
            hp=hp->right;
        }
    }
    if(val>prev ->data)
      prev->right=tnew;
    else
      prev->left=tnew;
    return root;
}*/
struct node *insert(struct node *root,int n)
{
    struct node *temp=root;
    struct node *new=(struct node *)malloc(sizeof(struct node));
    tnew->data=n;
    new->right=NULL;
    new->left=NULL;
    if(root=NULL)
    {
        root=new;
    }
}
void inorder(tn *root)
{   
    tn *hp;
    hp=root;
    if(hp!=NULL)
    {   
        inorder(hp->left);
        printf("%d",hp->data);
        inorder(hp->right);
    }
}
int main()
{   
    tn *root=NULL;
    printf("Hello Binary Search Tree");
    insert(5);
}