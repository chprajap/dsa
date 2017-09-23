#include<math.h>
#include<stdio.h>
int main(){
int i,n,j,p;
long long k,x,c=0,a[10];
scanf("%d",&n);
scanf("%lld",&k);
for(i=0;i<n;i++)
{
scanf("%lld",&a[i]);
}
for(i=1;i<pow(2,n);i++)
{
x=1;
for(j=0;j<n;j++)
{
if(i&1<<j)
x=x*a[j];
if(x>k)
break;
}
if(j==n)
c++;
}
printf("%lld\n",c);
return 0;
}
