#include<stdio.h>
void sum(int *add);
int main()
{
    int s;
    sum(&s);
    printf("\nThe summation is =%d",s);
    return 0;
}
void sum(int *add)
{
    int i;
    for(i=1,*add=0;i<102;i=i+2)
    {
            *add=*add+i;
            printf("%d + ",i);
    }
    printf("\b\b= ? ");
}
