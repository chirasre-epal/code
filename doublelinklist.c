#include<stdio.h>
#include<stdlib.h>
struct NODE
{
    int data;
    struct NODE *prev,*next;
};
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

