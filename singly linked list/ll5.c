                /* Check whether a loop exist or not*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
      int data;
      struct node *link;
};

void main()
{
      struct node *head=NULL;
      char ch;
      int x,choice;
      do
      {
             printf("Enter choice 1.to insert 2.to create loop 3.to print loop\n");
             scanf("%d",&choice);
             switch(choice)
             {
                   case 1:
                             printf("Enter no. to be insert in list\n");
                             scanf("%d",&x);
                             insert(&head,x);
                   break;
                   case 2:
                             do
                             {
                                         printf("Enter no. to be inserted in loop\n");
                                         scanf("%d",&x);
                                         insertloop(&head,x);
                   break;
                   case 3:
                             print(&head);
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
