#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int data;
    struct NODE *next;
};
struct NODE* create(int item,struct NODE *head)
{
   struct NODE *p,*s;
   p=(struct NODE *)malloc(sizeof(struct NODE));
   if(p==NULL)
   {
       printf("MEMORY NOT ALLOCATED");
       return head;
   }
   p->data=item;

   if(head==NULL)
        head=p;
    else
    {
        s=head;
        while(s->next!=head)
            s=s->next;
        s->next=p;
    }
    p->next=head;
   return head;
}
struct NODE* insert_at_first(int item,struct NODE *head)
{
   struct NODE *newnode,*ptr;
   newnode=(struct NODE *)malloc(sizeof(struct NODE));
   if(newnode==NULL)
   {
       printf("MEMORY NOT ALLOCATED");
       return head;
   }
   newnode->data=item;
   newnode->next=head;
   ptr=head;
   while(ptr->next!=head)
        ptr=ptr->next;
   ptr->next=newnode;
   head=newnode;
   return head;
}
struct NODE* insert_at_last(int item,struct NODE *head)
{
   struct NODE *newnode,*ptr;
   newnode=(struct NODE *)malloc(sizeof(struct NODE));
   if(newnode==NULL)
   {
       printf("MEMORY NOT ALLOCATED");
       return head;
   }
   newnode->data=item;
   newnode->next=head;
   ptr=head;
   while(ptr->next!=head)
        ptr=ptr->next;
   ptr->next=newnode;
   return head;
}
struct NODE* insert_before(int item,int x,struct NODE *head)
{
   struct NODE *newnode,*ptr,*pre;
   newnode=(struct NODE *)malloc(sizeof(struct NODE));
   if(newnode==NULL)
   {
       printf("MEMORY NOT ALLOCATED");
       return head;
   }
   newnode->data=item;
   ptr=head;
   while(ptr->data!=x)
   {
        pre=ptr;
        ptr=ptr->next;
   }
   newnode->next=ptr;
   pre->next=newnode;
   return head;
}
struct NODE* insert_after(int item,int x,struct NODE *head)
{
   struct NODE *newnode,*ptr;
   newnode=(struct NODE *)malloc(sizeof(struct NODE));
   if(newnode==NULL)
   {
       printf("MEMORY NOT ALLOCATED");
       return head;
   }
   newnode->data=item;
   ptr=head;
   while(ptr->data!=x)
   {
        ptr=ptr->next;
   }
   newnode->next=ptr->next;
   ptr->next=newnode;
   return head;
}
struct NODE* insert_at_position(int item,int x,struct NODE *head)
{
   struct NODE *newnode,*ptr,*pre;
   int count=1;
   newnode=(struct NODE *)malloc(sizeof(struct NODE));
   if(newnode==NULL)
   {
       printf("MEMORY NOT ALLOCATED");
       return head;
   }
   ptr=head;
   newnode->data=item;
   while(count!=x)
   {
        pre=ptr;
        ptr=ptr->next;
        count++;
   }
   newnode->next=ptr;
   pre->next=newnode;
   return head;
}
struct NODE * delete_at_first(struct NODE*head)
{
        struct NODE *ptr,*s;
        ptr=head;
        s=head;
        while(s->next!=head)
            s=s->next;
        s->next=ptr->next;
        head=ptr->next;
        free(ptr);
        return head;
}
struct NODE * delete_at_last(struct NODE*head)
{
        struct NODE *pre,*ptr;
        ptr=head;
        while(ptr->next!=head)
        {
            pre=ptr;
            ptr=ptr->next;
        }
        pre->next=head;
        free(ptr);
        return head;
}
struct NODE * delete_before(int x,struct NODE*head)
{
        struct NODE *ptr,*pre;
        ptr=head;
        if(x==head->data)
        {
            printf("THIS is the first node no node before it");
            return head;
        }
        while((ptr->next)->data!=x)
        {
            pre=ptr;
            ptr=ptr->next;
        }
        pre->next=ptr->next;
        free(ptr);
        return head;
}
struct NODE * delete_after(int x,struct NODE*head)
{
        struct NODE *ptr,*post;
        ptr=head;
        while(ptr->data!=x)
        {
            ptr=ptr->next;
        }
        post=ptr->next;
        ptr->next=post->next;
        free(post);
        return head;
}
struct NODE * delete_at_position(int x,struct NODE*head)
{
        struct NODE *ptr,*pre;
        int count=1;
        ptr=head;

        while(count!=x)
        {
            pre=ptr;
            ptr=ptr->next;
            count++;
        }
        pre->next=ptr->next;
        free(ptr);
        return head;
}
void display(struct NODE *head)
{
    struct NODE *ptr;
    ptr=head;
    while(ptr->next!=head)
    {
        printf(" %d ",ptr->data);
        ptr=ptr->next;
    }
    printf(" %d ",ptr->data);
}
int main()
{
    int item,choice,x;
    struct NODE *head=NULL;
    while(1)
    {
    printf("\n1: create\n2: insert at first\n3: insert at last\n4: insert before\n5: insert after\n6:insert at a position\n7: delete at first\n8: delete at last\n9: delete before\n10: delete after\n11: delete at a position\n12: display\n13: exit");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:
                printf("Enter the element:");
                scanf("%d",&item);
                head=create(item,head);
                break;
         case 2:
                printf("Enter the element you want to insert:");
                scanf("%d",&item);
                head=insert_at_first(item,head);
                break;
        case 3:
                printf("Enter the element you want to insert:");
                scanf("%d",&item);
                head=insert_at_last(item,head);
                break;
        case 4:
                printf("Enter the element before which you want to insert:");
                scanf("%d",&x);
                printf("Enter the element you want to insert:");
                scanf("%d",&item);
                head=insert_before(item,x,head);
                break;
        case 5:
                printf("Enter the element after which you want to insert:");
                scanf("%d",&x);
                printf("Enter the element you want to insert:");
                scanf("%d",&item);
                head=insert_after(item,x,head);
                break;
        case 6:
                printf("Enter the position where you want to insert:");
                scanf("%d",&x);
                printf("Enter the element you want to insert:");
                scanf("%d",&item);
                head=insert_at_position(item,x,head);
                break;
        case 7:
                head=delete_at_first(head);
                break;
        case 8:
                head=delete_at_last(head);
                break;
        case 9:
                printf("Enter the element before which you want to delete:");
                scanf("%d",&x);
                head=delete_before(x,head);
                break;
        case 10:
                printf("Enter the element after which you want to delete:");
                scanf("%d",&x);
                head=delete_after(x,head);
                break;
        case 11:
                printf("Enter the position where you want to delete:");
                scanf("%d",&x);
                head=delete_at_position(x,head);
                break;
        case 12:
                display(head);
                break;
        case 13:
                exit(0);
    }
}
return 0;
}
