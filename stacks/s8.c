                           /*prefix to postfix using stack*/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

char opnds[50][80],oprs[50];
int topd=-1,topr=-1;

void pushd(char *c)
{
       strcpy(opnds[++topd],c);
}

char *popd()
{
       return opnds[topd--];
}

void pushr(char c)
{
       oprs[++topr]=c;
}

char popr()
{
       return oprs[topr--];
}

int isempty(int t)
{
         if(t==-1)
                   return 1;
         else
                   return 0;   
}

void main()
{
         char opnd1[50],opnd2[50],prfx[50],str[50],opr[2],ch;
         int i,opndcnt=0;
         printf("Enter prefix expression\n");
         scanf("%[^\n]",prfx);
         printf("Prefix expression is %s\n",prfx);
         for(i=0;prfx[i]!='\0';i++)
         {
                   if(isalnum(prfx[i]))
                   {
                            str[0]=prfx[i];
                            str[1]='\0';
                            pushd(str);
                            opndcnt++;
                            if(opndcnt>=2)
                            {
                                   strcpy(opnd2,popd());
                                   strcpy(opnd1,popd());
                                   strcpy(str,opnd1);
                                   strcat(str,opnd2);
                                   ch=popr();
                                   opr[0]=ch;
                                   opr[1]='\0';
                                   strcat(str,opr);
                                   pushd(str);
                                   opndcnt-=1;  
                            }
                   }
                   else
                   {
                            pushr(prfx[i]);
                            if(opndcnt==1)
                                   opndcnt=0;
                   }
         }
         if(!isempty(topd))
         {
                   strcpy(opnd2,popd());
                                   strcpy(opnd1,popd());
                                   strcpy(str,opnd1);
                                   strcat(str,opnd2);
                                   ch=popr();
                                   opr[0]=ch;
                                   opr[1]='\0';
                                   strcat(str,opr);
                                   pushd(str);
                                   opndcnt-=1;  
         }
         printf("Postfix expression is %s\n",opnds[topd]);
}
