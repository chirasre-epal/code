#include<stdio.h>
void sqsum(int *sum)
{
    int i;
    for(i=5,*sum=0;i<=25;i++)
    {
        *sum=*sum+i*i;
        printf("%d\t+ ",i*i);
    }
    printf("\b\b = ?");
}
int main()
{
    int add;
    sqsum(&add);
    printf("\nThe sum of the squares from 5 to 25 is= %d",add);
    return 0;
}
