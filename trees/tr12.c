                 // C program to convert postfix expression to expression tree
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char data;
    struct node *left,*right;
};

int top=-1;
struct node *st[20];
struct node *root;

int check(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
         return 0;
    else
         return 1;  
}

void push(struct node *root)
{
    st[++top]=root;
}

struct node *pop()
{
    return st[top--];
}

void operand(char ch)
{
    struct node *root=malloc(sizeof(struct node));
    root->data=ch;
    root->left=root->right=NULL;
    push(root);
}

void operator(char ch)
{
    struct node *root=malloc(sizeof(struct node));
    root->data=ch;
    root->right=pop();
    root->left=pop();
    push(root);
}

void print(struct node *root)
{
    if(root==NULL)
          return;
    print(root->left);
    printf("%c",root->data);
    print(root->right);
}

void main()
{
    char s[100];
    printf("Enter postfix expression\n");
    scanf("%[^\n]",s);
    int i,l=strlen(s);
    for(i=0;i<l;i++)
    {
         if(check(s[i]))
             operand(s[i]);
         else
             operator(s[i]);
    } 
    printf("Inorder traversal is\n");
    print(st[top]);
    printf("\n");
}
