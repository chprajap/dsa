               // C program to delete node in BST(Binary Search Tree)
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(int x)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=x;
    ptr->left=ptr->right=NULL;
    return ptr;
}

struct node *insert(struct node *root,int x)
{
    if(root==NULL)
          return create(x);
    if(root->data>x)
    {
          root->left=insert(root->left,x);
          return root;
    }
    if(root->data<x)
    {
          root->right=insert(root->right,x);
          return root;
    }
}

struct node *minValue(struct node *root,int x)
{
    struct node *pttr=root;
    while(pttr->left!=NULL)
           pttr=pttr->left;
    return pttr;
}

struct node *delete(struct node *root,int x)
{
    if(root==NULL)
          return root;
    if(root->data>x)
          root->left=delete(root->left,x);
    else if(root->data<x)
          root->right=delete(root->right,x);
    else
    {
          if(root->left==NULL)
          {
               struct node *tmp=root->right;
               free(root);
               return tmp;
          }
          else if(root->right==NULL)
          {
               struct node *tmp=root->left;
               free(root);
               return tmp;
          }
          struct node *tmp=minValue(root->right,x);
          root->data=tmp->data;
          root->right=delete(root->right,tmp->data);
    }
    return root;
}

void print(struct node *root)
{
    if(root==NULL)
          return;
    print(root->left);
    printf("%d ",root->data);
    print(root->right);
}

void main()
{
    char ch;
    int choice,x;
    struct node *root=NULL;
    do
    {
         printf("Enter 1.to insert 2.to delete 3.to print\n");
         scanf("%d",&choice);
         switch(choice)
         {
              case 1:
                        printf("Enter no. to be inserted in bst\n");
                        scanf("%d",&x);
                        root=insert(root,x);
              break;
              case 2:
                        printf("Enter no. to be deleted in bst\n");
                        scanf("%d",&x);
                        root=delete(root,x);
              break;
              case 3:
                        print(root);
                        printf("\n");
              break;
              default:
                        printf("Invalid choice\n"); 
              break;
         }
         printf("Do you want to continue('y' or 'n')?\n");
         getchar();
         ch=getchar();
    }while(ch=='y');
}
