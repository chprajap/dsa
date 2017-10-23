                       // C program to construct a tree given postorder and inorder
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

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

struct node *constree(char in[],char post[],int str,int end,int *pi)
{
    
    if(str>end)
         return NULL;
    struct node *tr=create(post[*pi]);
    //printf("%c\n",tr->data);
    (*pi)--;
    if(str==end)
         return tr;
    int ii = search(in,str,end,tr->data);
    tr->right=constree(in,post,ii+1,end,pi);
    tr->left=constree(in,post,str,ii-1,pi);
    return tr;
}

void print(struct node *root)
{
    if(root==NULL)
         return;
    printf("%c ",root->data);
    print(root->left);
    print(root->right);
}

void main()
{
    char ch,ch1,in[50],post[50];
    int i=0,l1,l2;
    printf("Enter postorder of tree\n");
    while(ch!='\n')
    {
         scanf("%c",&ch);
         if(isalnum(ch))
              post[i++]=ch;
    }
    post[i]='\0';
    l1=i;
    i=0;
   // printf("%s\n",post);
    printf("Enter inorder of tree\n");
    
    while(ch1!='\n')
    {
          
         scanf("%c",&ch1);
         
         if(isalnum(ch1))
              in[i++]=ch1;
    }
    in[i]='\0';
    l2=i;
    //printf("%s\n",in);
    int pi=l1-1;   
    struct node *root=constree(in,post,0,l1-1,&pi);
    printf("Preorder of a tree is ");
    print(root);
    printf("\n");   
}
