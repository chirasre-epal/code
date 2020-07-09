#include<stdio.h>
int main()
{
    int n,n1,rn=0;
    printf("Enter a number: ");
    scanf("%d",&n);
    n1=n;
    while(n>0)
    {
        rn=10*rn+n%10;
        n/=10;
    }
    printf("Reverse number: %d\n",rn);
    if(n1==rn)
        printf("The number is a pallindrome number");
    else
        printf("The number is not a pallindrome number");
}
