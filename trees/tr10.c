                // C Program to insert and search in BST(Binary Search Tree)

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
    { 
         return create(x);
          
    }
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

int search(struct node *root,int x)
{
    if(root==NULL)
          return 0;
    if(root->data==x)
          return 1;
    if(root->data>x)
          return search(root->left,x);
    if(root->data<x)
          return search(root->right,x);    
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
         printf("Enter 1.to insert 2.to search 3.to print\n");
         scanf("%d",&choice);
         switch(choice)
         {
              case 1:
                        printf("Enter no. to be inserted in bst\n");
                        scanf("%d",&x);
                        root=insert(root,x);
              break;
              case 2:
                        printf("Enter no. to be searched in bst\n");
                        scanf("%d",&x);
                        if(search(root,x))
                              printf("Element found\n");
                        else
                              printf("Element not found\n");
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
