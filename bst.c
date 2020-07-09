#include<stdio.h>
#include<stdlib.h>
typedef struct tree
{
    int data;
    struct tree *left,*right;
}bnode;
bnode *root=NULL;
bnode *par=NULL;
void create(int item)
{
    bnode *s,*p;
    p=(bnode *)malloc(sizeof(bnode));
    p->data=item;
    p->left=NULL;
    p->right=NULL;
    s=root;
    if(s==NULL)
    {
        root=p;
    }
    else
    {
        while(s!=NULL)
        {
            if(item<s->data)
            {
                if(s->left==NULL)
                {
                    s->left=p;
                    break;
                }
                else
                    s=s->left;
            }
            else
            {
                if(s->right==NULL)
                {
                    s->right=p;
                    break;
                }
                else
                    s=s->right;
            }
        }
    }
}
bnode * search(int item)
{
    bnode *loc=root;
    while(loc!=NULL && loc->data!=item )
    {
        if(item<loc->data)
        {
            par=loc;
            loc=loc->left;
        }
        else
        {
            par=loc;
            loc=loc->right;
        }
    }

        return loc;
}
void post_order(bnode *root)
{
    if(root!=NULL)
    {
        post_order(root->left);
        post_order(root->right);
        printf(" %d ",root->data);
    }
}
void in_order(bnode *root)
{
    if(root!=NULL)
    {
        in_order(root->left);
        printf(" %d ",root->data);
        in_order(root->right);

    }
}
void pre_order(bnode *root)
{
    if(root!=NULL)
    {
        printf(" %d ",root->data);
        pre_order(root->left);
        pre_order(root->right);

    }
}
bnode * in_successor(bnode *loc)
{
    bnode *suc=loc->right;
    par=loc;
    if(suc->left!=NULL)
    {
        par=suc;
        suc=suc->left;
    }
    return suc;

}
void del_leaf(bnode *loc)
{
    if(par->left==loc)
        par->left=NULL;
    else
        par->right=NULL;
    free(loc);
}
void del_only_left_child(bnode *loc)
{
    if(par->left==loc)
    {
        par->left=loc->left;
    }
    else
    {
        par->right=loc->left;
    }
    free(loc);
}
void del_only_right_child(bnode *loc)
{
    if(par->left==loc)
    {
        par->left=loc->right;
    }
    else
    {
        par->right=loc->right;
    }
    free(loc);
}
void del_with_both_child(bnode *loc)
{
    bnode *suc=in_successor(loc);
    loc->data=suc->data;
    if(suc->right==NULL)
        del_leaf(suc);
    else
        del_only_right_child(suc);
}
void del(int item)
{
    bnode *loc=search(item);
    if(loc->left==NULL&&loc->right==NULL)
    {
        del_leaf(loc);
    }
    else if(loc->right==NULL)
    {
        del_only_left_child(loc);
    }
    else if(loc->left==NULL)
    {
        del_only_right_child(loc);
    }
    else
    {
        del_with_both_child(loc);
    }
}
int main()
{
    int item,choice;
    bnode *loc;
    while(1)
    {
        printf("\n1: create\n2: pre_order traverse\n3: in_order traverse\n4: post_order_traverse\n5: search\n6: delete\n7: exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1: printf("enter the element: ");
                scanf("%d",&item);
                create(item);
                break;
        case 2: pre_order(root);
                break;
        case 3: in_order(root);
                break;
        case 4: post_order(root);
                break;
        case 5: printf("enter the element u wnt to search: ");
                scanf("%d",&item);
                loc=search(item);
                if(loc)
                {
                    printf("SEARCH SUCCESSFULL");
                }
                else
                {
                    printf("SEARCH UNSUCCESSFULL");
                }
                break;
        case 6: printf("enter the element u wnt to delete: ");
                scanf("%d",&item);
                del(item);
                break;
        case 7: exit(0);
        }
    }
}
