                 /* Infix to postfix expression using stacks */
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct node
{
      char data;
      struct node *link;
};

void push(struct node **head,char ch)
{
      struct node *ptr=malloc(sizeof(struct node));
      ptr->data=ch;
      ptr->link=*head;
      *head=ptr;
}

char pop(struct node **head)
{
      struct node *tmp=*head;
      char ch=tmp->data;
      *head=tmp->link;
      free(tmp);
      return ch;
}

char top(struct node **head)
{
      return (*head)->data;
}

int isoperator(char ch)
{
      switch(ch)
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

int isempty(struct node **head)
{
      if(*head==NULL)
              return 1;
      else
              return 0;
}

int prec(char ch)
{
      switch(ch)
      {
              case '+':
              case '-':
                         return 1;
              break;
              case '*':
              case '/':
                         return 2;
              break;
              case '^':
                         return 3;
              break;
              default:
                         return 0;
              break;
      }
}

void post(struct node **head,char s[])
{
      int i,j=0;
      char res[100];
      for(i=0;s[i]!='\0';i++)
      {
             if(s[i]=='(')
                     push(head,s[i]);
             else if((s[i]>='0' && s[i]<='9') || isalpha(s[i]))
                     res[j++]=s[i];
             else if(isoperator(s[i]))
             {
                     while(!isempty(head) && prec(s[i])<=prec(top(head)))
                              res[j++]=pop(head);
                     push(head,s[i]);
             } 
             else if(s[i]==')')
             {
                     char c=pop(head);
                     while(c!='(' && !isempty(head))
                     { 
                              res[j++]=c;
                              c=pop(head);
                     }
             }
      }
      while(!isempty(head))
             res[j++]=pop(head);
      printf("Postfix expression is %s\n",res);
}

void main()
{
      struct node *head=NULL;
      char s[100];
      printf("Enter infix expression\n");
      scanf("%[^\n]",s);
      post(&head,s);
}
