#include<stdio.h>
main()
{
    int a,b;
    printf("Enter two numbers: ");
    scanf("%d %d",&a,&b);
    printf("\nThe numbers before swap: %d %d",a,b);
    a=a^b;
    b=a^b;
    a=a^b;
    printf("\nThe numbers after swap: %d %d",a,b);
}
