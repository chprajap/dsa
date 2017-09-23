#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long reverse(long int a);
int main() {
long i,j,a,c=0;
long long k;
scanf("%ld %ld %lld",&i,&j,&k);
for(a=i;a<=j;a++)
{
if(abs(a-reverse(a))%k==0)
c++;
}
printf("%ld\n",c);
return 0;
}

long reverse(long int a){
long b=0;
while(a){
b=(b*10)+(a%10);
a=a/10;
}
return b;
}


