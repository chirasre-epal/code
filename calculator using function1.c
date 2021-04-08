#include<stdio.h>
void sum(int no1,int no2);
void sub(int no1,int no2);
void multiply(int no1,int no2);
void div(int no1,int no2);
int main()
{
    float no1,no2,result;
    int n;
    printf("\nEnter two numbers:");
    scanf("%f %f",&no1,&no2);
    sum(no1,no2);
    sub(no1,no2);
    multiply(no1,no2);
    div(no1,no2);
    return 0;
}
void sum(int no1,int no2)
{
    printf("The sum is %d\n",no1+no2);
}
void sub(int no1,int no2)
{
    printf("The difference is %d\n",no1-no2);
}
void multiply(int no1,int no2)
{
    printf("The product is %d\n",no1*no2);
}
void div(int no1,int no2)
{
    if(no2==0)
        printf("SYNTAX ERROR\n");
    else
        {
            printf("The division is %.2f\n",(float)no1/no2);
        }
}
