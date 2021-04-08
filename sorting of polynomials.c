#include<stdio.h>
#include<stdlib.h>
struct poly
{
    int co;
    int exp;
    struct poly* next;
};

struct poly* create(struct poly * head)
{
        int coef,expo;
        printf("Enter the coefficient and exponent:");
        scanf("%d %d",&coef,&expo);
        struct poly* newnode,*s;
        newnode=(struct poly *)malloc(sizeof(struct poly));
        newnode->co=coef;
        newnode->exp=expo;
        newnode->next=NULL;
        s=head;
        if(s==NULL)
        {
            head=newnode;
        }
        else
        {
            while(s->next!=NULL)
            {
                s=s->next;
            }
            s->next=newnode;
        }
        return head;
}
void display(struct poly *head)
{
    struct poly *s;
    s=head;
    while(s->next!=NULL)
    {
        printf("%dX^%d+",s->co,s->exp);
        s=s->next;
    }
    printf("%dX^%d",s->co,s->exp);
}
void sort(struct poly *head)
{
    int max,temp;
    struct poly *s,*p,*t;
    p=head;
    while(p->next!=NULL)
    {
        max=p->exp;
        s=p->next;
        while(s!=NULL)
        {

            if(s->exp > max)
            {
                max=s->exp;
                t=s;
            }
            s=s->next;
        }
        t->exp=p->exp;
        p->exp=max;
        temp=t->co;
        t->co=p->co;
        p->co=temp;
        p=p->next;
    }
}

int main()
{
    struct poly *head=NULL;
    int choice;

    while(1){
    printf("\n1:Create\n2:Display\n3:Sort\n4:Exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
                head=create(head);
                break;
        case 2: display(head);
                break;
        case 3: sort(head);
                break;
        case 4: exit(0);
        default: printf("Wrong choice");
    }
    }
}
