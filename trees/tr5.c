                    /* C program to check for perfect binary tree */

#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create(struct node *root,int x)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=x;
    ptr->left=ptr->right=NULL;
    return ptr;
}

void print(struct node *root)
{
    if(root==NULL)
          return;
    printf("%d ",root->data);
    print(root->left);
    print(root->right);
}

int depth(struct node *root)
{
    if(root==NULL)
         return 0;
    else
         return (1+depth(root->left));
}

int perfect(struct node *root,int d,int level)
{
    if(root==NULL)
         return 1;
    if(root->left==NULL && root->right==NULL)
         return (d==(level+1));
    if(root->left==NULL || root->right==NULL)
         return 0;
    return (perfect(root->left,d,level+1) && perfect(root->right,d,level+1));
}

int check(struct node *root)
{
    int d=depth(root);
    return perfect(root,d,0);
}

void main()
{
    struct node *root=NULL;
    struct node *pr=NULL;
    char ch;
    int choice,x,c,d,nc,i;
    do
    {
         printf("Enter 1.to insert 2.to print 3.to check for perfect binary tree\n");
         scanf("%d",&choice);
         switch(choice)
         {
              case 1:
                        c=0;
                        
                        while(c==0)
                        {
                            printf("Enter no. to be inserted\n");
                            scanf("%d",&x);
                            if(root==NULL)
                            {
                                 root=create(root,x);
                                 pr=root;
                                 c=1;
                            }
                            else
                            {
                              pr=root;
                              while(c==0)
                              {
                                 printf("Do you want to insert left(1) or right(2)?\n");
                                 scanf("%d",&d);
                                 if(d==1)
                                 {
                                      if(pr->left==NULL)
                                      {
                                         pr->left=create(root,x);
                                         c=1;
                                      }
                                      else
                                      {
                                         pr=pr->left;
                                      }
                                 }
                                 else if(d==2)
                                 {    
                                      if(pr->right==NULL)
                                      {
                                         pr->right=create(root,x);
                                         c=1;
                                      }
                                      else
                                      {
                                         pr=pr->right;
                                      }
                                 }
                              }
                            }
                        }
              break;
              case 2:
                        print(root);
                        printf("\n");
              break;
              case 3:
                       
                        if(check(root))
                          printf("tree is perfect binary tree\n");
                        else
                          printf("tree isn't perfect binary tree\n");
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

