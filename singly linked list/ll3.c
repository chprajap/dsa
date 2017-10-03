                  /* delete nth node when you are on nth node without using another pointer */

#include<stdio.h>
#include<stdlib.h>

struct node
{
      int data;
      struct node *link;
};

void insert(struct node **head,int x)
{
      struct node *ptr=malloc(sizeof(struct node));
      ptr->data=x;
      ptr->link=*head;
      *head=ptr;
}

void delete(struct node **head,int x)
{
      int c=1;
      if(*head==NULL)
      {
              printf("List is empty so can't delete\n");
              return;
      }
      struct node *tmp=*head;
      if(x==1 && tmp->link==NULL)
      {
              printf("Can't delete as there is only one node so can't swap it\n");
              return;
      }

      while(tmp->link!=NULL)             /* We can't delete last node*/
      {
              if(c==x)
              {
                    int swap=tmp->data;
                    tmp->data=tmp->link->data;
                    tmp->link->data=swap;
                    tmp->link=tmp->link->link;
                    return;
              }
              c++;
              tmp=tmp->link;
      }
      if(tmp->link==NULL)
      {
              printf("We can't delete\n");
      }
}

void print(struct node **head)
{
      if(*head==NULL)
      {
             printf("list is empty so can't print\n");
      }
      struct node *ptr=*head;
      while(ptr!=NULL)
      {
             printf("%d ",ptr->data);
             ptr=ptr->link;
      }
      printf("\n");
}

void sort(struct node **head)
{
      struct node *tmp=*head;
      while(tmp!=NULL)
      {
             struct node *tmp1=tmp;
             while(tmp1!=NULL)
             { 
                    if(tmp->data > tmp1->data)
                    {
                              int c=tmp->data;
                              tmp->data=tmp1->data;
                              tmp1->data=c;
                    }
                    tmp1=tmp1->link;
             }
             tmp=tmp->link;
      }
}

void main()
{
      struct node *head=NULL;
      char ch;
      int x,choice;
      do
      {
             printf("Enetr choice\n");
             scanf("%d",&choice);
             switch(choice)
             {
                   case 1:
                             printf("Enter no. to be insert in list\n");
                             scanf("%d",&x);
                             insert(&head,x);
                   break;
                   case 2:
                             printf("Enter pos. to be deleted\n");
                             scanf("%d",&x);
                             delete(&head,x);
                   break;
                   case 3:
                             print(&head);
                   break;
                   case 4:
                             sort(&head);
                   break;
                   default:
                             printf("Invalid input\n");
                   break;
             }
             printf("Do you want to continue\n");
             getchar();
             ch = getchar();
             
      }while(ch=='y');

}
