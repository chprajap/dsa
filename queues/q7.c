                            /* Priority queue using arrays */
#include<stdio.h>

int q[2][5],f=-1,r=-1;

void enqueue(int x,int p)
{
        if(f==(r+1)%5)
        {
               printf("Queue is full so can't enqueue\n");
               return;
        }
        else if(f==-1 && r==-1)
        {
               f=r=0;
        }
        else
        {
               r=(r+1)%5;
        }
        q[0][r]=x;
        q[1][r]=p;
}

int gethighestpriority()
{
        int tmp=q[1][0];
        int i,j=0;
        for(i=1;i<5;i++)
        {
               if(q[1][i]<tmp)
               {        
                      tmp=q[1][i];
                      j=i;
               }
        }
        return j;
}

void dequeue()
{
        if(f==-1 && r==-1)
        {
               printf("Queue is empty so can't dequeue\n");
               return;
        }
        else if(f==r)
        {
               q[0][f]=0;
               q[1][f]=999;
               f=r=-1;
        }
        else
        {
               int c=gethighestpriority();
               q[0][c]=q[0][f];
               q[1][c]=q[1][f];
               q[0][f]=0;
               q[1][f]=999;
               f=(f+1)%5;
        }
}

void print()
{
        int i;
        for(i=0;i<5;i++)
        {
               printf("(%d %d) ",q[0][i],q[1][i]);
        }
        printf("\n");
}

void main()
{
       int i;
       for(i=0;i<5;i++)
       {
               q[0][i]=0;
               q[1][i]=999;
       }
       int choice,x,p;
       char ch;
       do
       {
              printf("Enter choice 1.to enqueue 2.to dequeue 3.to print\n");
              scanf("%d",&choice);
              switch(choice)
              {
                       case 1:
                                  printf("Enter no. & priority to enqueue\n");
                                  scanf("%d %d",&x,&p);
                                  enqueue(x,p);
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
