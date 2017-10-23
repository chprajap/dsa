                       // C program to construct a tree given preorder and inorder
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
    char data;
    struct node *left;
    struct node *right;
};

struct node *create(char ch)
{
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=ch;
    ptr->left=ptr->right=NULL;
    return ptr;
}

int search(char in[],int str,int end,char ch)
{
    int i;
    for(i=str;i<=end;i++)
    {
         if(in[i]==ch)
             return i;
    }
}

struct node *constree(char in[],char pre[],int str,int end)
{
    static int pi=0;
    if(str>end)
         return NULL;
    struct node *tr=create(pre[pi++]);
    if(str==end)
         return tr;
    int ii = search(in,str,end,tr->data);
    tr->left=constree(in,pre,str,ii-1);
    tr->right=constree(in,pre,ii+1,end);
    return tr;
}

void print(struct node *root)
{
    if(root==NULL)
         return;
    print(root->left);
    print(root->right);
    printf("%c ",root->data);
}

void main()
{
    char ch,ch1,in[50],pre[50];
    int i=0,l1,l2;
    printf("Enter preorder of tree\n");
    while(ch!='\n')
    {
         scanf("%c",&ch);
         if(isalnum(ch))
              pre[i++]=ch;
    }
    l1=i;
    i=0;
    //printf("%s\n",pre);
    printf("Enter inorder of tree\n");
    
    while(ch1!='\n')
    {
          
         scanf("%c",&ch1);
         
         if(isalnum(ch1))
              in[i++]=ch1;
    }
    l2=i;
    //printf("%s\n",in);
    
    struct node *root=constree(in,pre,0,l1-1);
    printf("Postorder of a tree is ");
    print(root);
    printf("\n");   
}
