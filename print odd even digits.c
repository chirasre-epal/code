#include<stdio.h>
int main()
{
    int n,odd[10],even[10],i=0,j=0,k;
    printf("Enter the number:");
    scanf("%d",&n);
    while(n>0)
    {
        if((n%10)%2==0)
        {
            even[i]=n%10;
            i++;
        }
        else
        {
            odd[j]=n%10;
            j++;
        }
        n/=10;
    }
    printf("The even digits are: ");
    for(k=0;k<i;k++)
    {
        printf("%d ",even[k]);
    }
    printf("The odd digits are: ");
    for(k=0;k<j;k++)
    {
        printf("%d ",odd[k]);
    }
}
