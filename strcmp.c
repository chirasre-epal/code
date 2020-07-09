#include<stdio.h>
int xstrcmp(char *s,char *t);
int main()
{
    char str1[50],str2[50];
    int result;
    printf("Enter first string:\n");
    gets(str1);
    printf("Enter second string:\n");
    gets(str2);
    result=xstrcmp(str1,str2);
    if(result==0)
    {
        printf("The strings are equal");
    }
    else if(result<0)
    {
        printf("String 1 is smaller than string 2 difference of ascii value=%d",result);
    }
    else
    {
        printf("String 1 is greater than string 2 difference of ascii value=%d",result);
    }
}
int xstrcmp(char *s,char *t)
{
    if(*s==*t)
    {
        if(*s=='\0'&&*t=='\0')
        {
            return 0;
        }
        xstrcmp(s+1,t+1);
    }
    else
        return (*s-*t);
}
