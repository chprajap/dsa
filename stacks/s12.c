                      /* Check for a balanced parenthesis using stacks*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
     char data;
     struct node *link;
};

void push(struct node **head,char c)
{
     struct node *ptr=malloc(sizeof(struct node));
     ptr->data=c;
     ptr->link=*head;
     *head=ptr;
}

void pop(struct node **head)
{
     struct node *ptr=*head;
     *head=(*head)->link;
     free(ptr);
}

int isempty(struct node **head)
{
     if(*head==NULL)
            return 1;
     else
            return 0;
}

char top(struct node **head)
{
     if(isempty(head))
            return 0;
     else
            return (*head)->data;
}


void main()
{
     struct node *head=NULL;
     char s[100];
     printf("Enter a string\n");
     scanf("%[^\n]",s);
     int i;
     for(i=0;s[i]!='\0';i++)
     {
               if(s[i]=='{' || s[i]=='(' || s[i]=='[')
                           push(&head,s[i]);
               else if(s[i]=='}' || s[i]==']' || s[i]==')')
               {
                         if( (s[i]=='}' && top(&head)!='{') || (s[i]==')' && top(&head)!='(') || (s[i]==']' && top(&head)!='[') )
                         {
                                   printf("Not balanced paranthesis\n");
                                   return;
                         }
                         pop(&head);
               }
     }
     if(isempty(&head))
            printf("Balanced parenthesis\n");
     else
            printf("Not balanced parenthesis\n");
}
