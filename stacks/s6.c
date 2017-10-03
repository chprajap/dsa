                      /* evaluate postfix expression */
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
      int data;
      struct node *link;
};

int isoperator(char c)
{
      switch(c)
      {
              case '+':
              case '-':
              case '*':
              case '/':
              case '^':
                           return 1;
              break;
              default:
                           return 0;
              break;
      }
}

void push(struct node **head,int c)
{
      struct node *ptr=malloc(sizeof(struct node));
      ptr->data=c;
      ptr->link=*head;
      *head=ptr;
}

int pop(struct node **head)
{
     struct node *tmp=*head;
     int d=tmp->data;
     *head=tmp->link;
     free(tmp);
     return d;
}

int getValue(int x,int y,char ch)
{
     switch(ch)
     {
             case '+':
                      return x+y;
             break;
             case '-':
                      return x-y;
             break;
             case '*':
                      return x*y;
             break;
             case '/':
                      return x/y;
             break;
             case '^':
                      return x^y;
             break;            
             default:
                      return 0;
             break;
     }
}

void post(struct node **head, char s[])
{
      int i,l=strlen(s);
      for(i=0;i<l;i++)
      {
             if(s[i]>='0' && s[i]<='9')
             {
                      push(head,s[i]-'0');
             }
             else if(isoperator(s[i]))
             {
                      int op1= pop(head);
                      int op2= pop(head);
                      push(head,getValue(op2,op1,s[i]));
             }
      }
      printf("value of postfix expression is %d\n",pop(head));
}

void main()
{
      struct node *head=NULL;
      char s[100];
      printf("Enter postfix expression\n");
      scanf("%[^\n]",s);
      post(&head,s);
}
