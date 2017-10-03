                  /* Insert at end & delete node given a position */

#include<stdio.h>
#include<stdlib.h>

struct node
{
        int data;
        struct node *link;
};

void insert(struct node **head,int x)
{
       struct node *ptr=(struct node *)malloc(sizeof(struct node));
       struct node *tmp=*head;
       ptr->data=x;
       ptr->link=NULL;
       if(*head==NULL)
       {
              *head=ptr;
               return;
       }
       while(tmp->link!=NULL)
               tmp=tmp->link;
       tmp->link=ptr;
}

void delete(struct node **head,int x)
{
      struct node *tmp=*head,*tmp1;
      int c=1;
      if(*head==NULL)
      {
             printf("No element to be deleted as it is empty\n");
             return;
      }
      if(c==x)
      {
             *head=(*head)->link;
             free(tmp);
             return;
      }
      while(tmp!=NULL)
      {
             if(c==x)
             {
                    tmp1->link=tmp->link;
                    free(tmp);
                    return;
             }
             c++;
             tmp1=tmp;
             tmp=tmp->link;
      }
      if(tmp==NULL)
      {
             printf("Element not found enter valid element\n");
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
                             printf("Enter no. to be insert in list at end\n");
                             scanf("%d",&x);
                             insert(&head,x);
                   break;
                   case 2:
                             printf("Enter position to be deleted\n");
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
