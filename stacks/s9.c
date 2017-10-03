                          /* Reverse a string & check whether it's a palindrome or not using stack*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

char pop(struct node **head)
{
     struct node *ptr=*head;
     char c=ptr->data;
     *head=(*head)->link;
     free(ptr);
     return c;
}

int isempty(struct node **head)
{
     if(*head==NULL)
            return 1;
     else
            return 0;
}

void main()
{
     struct node *head=NULL;
     char s[100],r[100];
     int i;
     printf("Enter a string\n");
     scanf("%[^\n]",s);
     strcpy(r,s);
     for(i=0;s[i]!='\0';i++)
              push(&head,s[i]);
     i=0;
     while(!isempty(&head))
              s[i++]=pop(&head);
     s[i]='\0';
     printf("Reversed string is %s\n",s);
     if(strcmp(s,r)==0)
     {
              printf("String %s is palindrome\n",r);
     }     
     else
     {
              printf("String %s is not palindrome\n",r);
     }
}

