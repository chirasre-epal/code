#include<stdio.h>
#include<stdlib.h>
#define MAXSTK 20
int push(int st[],int top,int item)
{
    if(top==MAXSTK-1)
    {
        printf("overflow");
    }
    else
    {
        top++;
        st[top]=item;
    }
    return top;
}
int pop(int st[],int top)
{
    int item;
    if(top==-1)
    {
        printf("underflow");
    }
    else
    {
        item=st[top];
        top--;
        printf("Item deleted: %d",item);
    }
    return top;
}
void display(int st[],int top)
{
    int i;
    if(top==-1)
        printf("Empty stack");
    else
    {
        for(i=0;i<=top;i++)
        {
            printf(" %d ",st[i]);
        }
    }
}
int main()
{
    int arr[20],stack[20],d,choice,item,n=0,top=-1,j=0;
    FILE *fp;
    fp=fopen("no.txt","r");
    if(fp==NULL)
    {
        printf("ERROR!");
        exit(0);
    }
     while(!feof(fp))
    {
        fscanf(fp,"%d",&d);
        arr[n++]=d;
    }
    fclose(fp);
    while(1)
    {
        printf("\nPress 1 for PUSH\nPress 2 for POP\nPress 3 for DISPLAY\nPress 4 for EXIT");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: item=arr[j++];
                    top=push(stack,top,item);
                    break;
            case 2: top=pop(stack,top);
                    break;
            case 3: display(stack,top);
                    break;
            case 4: exit(0);
        }
    }
    return 0;
}
