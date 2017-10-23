                              // C program to convert infix expression to expression tree
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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

void print1(struct node *root)
{
    if(root==NULL)
          return;
    printf("%c",root->data);
    print1(root->left);
    print1(root->right);
}

void print2(struct node *root)
{
    if(root==NULL)
          return;
    print2(root->left);
    print2(root->right);
    printf("%c",root->data);
}

            // Conversion of infix expression to postfix
struct node1
{
   char data;
   struct node1 *link;
};

struct node1 *head=NULL;

void push1(char ch)
{
   struct node1 *ptr=malloc(sizeof(struct node1));
   ptr->data=ch;
   ptr->link=head;
   head=ptr;
}

char pop1()
{
   struct node1 *tmp=head;
   char ch=tmp->data;
   head=tmp->link;
   free(tmp);
   return ch;
}

int isoperator(char ch)
{
    if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^')
         return 1;
    else
         return 0;
}

int isempty()
{
    if(head==NULL)
       return 1;
    else
       return 0;
}

int prec(char ch)
{
    switch(ch)
    {
         case '^':
                   return 3;
         case '*':
         case '/': 
                   return 2;
         case '+':
         case '-':
                   return 1;
         default:
                   return 0;
      
    }
}

void postfix(char s[100])
{
    int i,l1=strlen(s),j=0;
    char r[100];
    for(i=0;i<l1;i++)
    {
          if(s[i]=='(')
                push1(s[i]);
          else if(isalnum(s[i]))
          {
                r[j++]=s[i];
          }
          else if(isoperator(s[i]))
          {
                while((!isempty()) && (prec(head->data)>=prec(s[i])))
                {
                     r[j++]=pop1();
                }
                push1(s[i]);
          }
          else if(s[i]==')')
          {
                char ch2=pop1();
                while(ch2!='(')
                {    r[j++]=ch2;
                     ch2=pop1();
                    
                }
          }
    }
    while(!isempty())
          r[j++]=pop1();
    
    strcpy(s,r);
}


void main()
{
    char s[100];
    printf("Enter infix expression\n");
    scanf("%[^\n]",s);
    postfix(s);
    
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
    printf("Preorder traversal is\n");
    print1(st[top]);
    printf("\n");
    printf("Postorder traversal is\n");
    print2(st[top]);
    printf("\n");
}
