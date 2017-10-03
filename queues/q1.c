                        /* Queue using circular arrays*/

#include<stdio.h>
int a[10]={0},f=-1,r=-1;

int isfull()
{
        if(f==(r+1)%10)
               return 1;
        else
               return 0; 
}

int isempty()
{
        if(f==-1 && r==-1)
               return 1;
        else
               return 0;
}

void enqueue(int x)
{
        if(isfull())
        { 
               printf("Queue is full so can't enqueue\n");
               return;
        }
        else if(f==-1 && r==-1)
        {
               f=r=0;
        }
        else
               r=(r+1)%10;
        a[r]=x;
}

void dequeue()
{
        if(isempty())
        {
               printf("Queue is empty so can't dequeue\n");
               return;
        }
        else if(f==r)
        {
               a[f]=0;
               f=r=-1;
        }
        else
        {
               a[f]=0;
               f=(f+1)%10;
        }
}

void print()
{
        int i;
        for(i=0;i<10;i++)
        {
               printf("%d ",a[i]);
        }
        printf("\n");
}

void main()
{
       int choice,x;
       char ch;
       do
       {
              printf("Enter choice 1.to enqueue 2.to dequeue 3.to print\n");
              scanf("%d",&choice);
              switch(choice)
              {
                       case 1:
                                  printf("Enter no. to enqueue\n");
                                  scanf("%d",&x);
                                  enqueue(x);
                       break;
                       case 2:
                                  dequeue();
                       break;
                       case 3:
                                  print();
                       break;
                       default:
                                  printf("Invalid choice\n");
                       break;
              }
              printf("Do you want to continue('y' or 'n')?\n");
              getchar();
              ch=getchar();
       }while(ch=='y');
}
