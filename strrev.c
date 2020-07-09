#include<stdio.h>
void xstrrev(char *s);
int main()
{
    char str1[50];
    printf("Enter the string:\n");
    gets(str1);
    xstrrev(str1);
    printf("The reversed string is: %s",str1);
    return 0;
}
void xstrrev(char *s)
{
    int count,i;
    char temp;
    while(*s!='\0')
    {
        count++;
        s++;
    }
    s-=count;
    for(i=0;i<count;i++)
    {
        temp=*s;
        *s=*(s+count-i-1);
        *(s+count-i-1)=temp;
        s++;
    }
}
