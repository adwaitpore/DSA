///Binary Search Tree 
#include<stdio.h>
#include<stdlib.h>
 
 
struct node
{
	 int data;
	struct node *left;
	struct node *right;
};
struct node *ins(struct node *root,int v)
{
	struct node *q=root;
	struct node *follow=NULL;
	struct node *p=(struct node *)malloc(sizeof(struct node));
	 p->data=v;
	 p->left=NULL;
	 p->right=NULL;
 
	 if(root==NULL)
	 {
		  root=p;
		return root;
	}
 
	 while(q!=NULL)
	 {
		  follow=q;
		if(q->data<p->data)
		{
			 q=q->right;
		}
		else
		 {
			  q=q->left;
		}
	}
	if(follow->data>p->data)
	{
		  follow->left=p;
	}
	else
	{
		 follow->right=p;
	}
	return root;
}
 
 

void inorder(struct node*root)
{
if(root!=NULL)
{
 
  inorder(root->left);
    printf("%d\t",root->data);
  inorder(root->right);
}
}
 
 
int main()
{
   struct node *root=NULL;
  root=ins(root,5);
  root=ins(root,5555);
  root=ins(root,50);
  inorder(root);
  return 0;
}