#include<stdio.h>
#include<conio.h>
int search(int x,int *array,int size);
void wincheck(char *array,int *temp);
int main()
{
    char s,sign1,sign2,arr[10];
    int c=1,i,j,k=0,choice,temp=1,flag;
    int ind[9]={0,0,0,0,0,0,0,0,0};
    printf("\t\t\t\tLet's play the game\n\n\n\t");
    for(c=1;c<10;c++)
    {
        printf(" %d ",c);
        if(c%3==0)
            printf("\n\t----------\n\t");
        else
            printf("|");
    }

    printf("\tEnter the sign you want to put:\n\t");
    scanf("%s",&s);
    sign1=toupper(s);
    sign2=(sign1=='O')?'X':'O';
    printf("\n So player 1 sign is %c and player 2 sign is %c",sign1,sign2);
    for(c=1;c<=5;c++)
    {   again:
        printf("\n\n1st person's turn\n\t");
        printf("Choose a cell number \n\n\t");
        scanf("%d",&choice);
        flag=search(choice,ind,9);
        if(flag)
        {
        for(i=1;i<10;i++)
        {
            flag=search(i,ind,9);
            if(flag)
            {
                if(i==choice)
                {
                    arr[i]=sign1;
                    ind[k]=i;
                    k++;
                }
                else
                {
                    arr[i]=' ';
                }
            }
        }

        printf("\t");
        for(j=1;j<10;j++)
        {
            printf("%c",arr[j]);
            if(j%3==0)
                printf("\n\t----------\n\t");
            else
                printf(" | ");
        }
        }
        else
        {
            printf("This place is already filled");
            goto again;
        }
        //if(c==5)
          //  break;
        if(c>2)
        wincheck(arr,&temp);
        if(temp==0)
            break;
        again2:
        printf("\n\n2nd person's turn\n\t");
        printf("Choose a cell number \n\n\t");
        scanf("%d",&choice);
        flag=search(choice,ind,9);
        if(flag)
        {
        for(i=1;i<10;i++)
        {
            flag=search(i,ind,9);
            if(flag)
            {
                if(i==choice)
                {
                    arr[i]=sign2;
                    ind[k]=i;
                    k++;
                }
                /*else
                {
                    arr[i]=arr[i];
                }*/
            }
        }
        printf("\t");
        for(j=1;j<10;j++)
        {

            printf("%c",arr[j]);
            if(j%3==0)
                printf("\n\t----------\n\t");
            else
                printf(" | ");
        }
        }
        else
        {
            printf("This place is already filled");
            goto again2;
        }
        if(c>2)
        wincheck(arr,&temp);
        if(temp)
            continue;
        else
            break;
    }
    if(temp)
    printf("\n\t\tThis is a draw match");
    return 0;
}
void wincheck(char *arr,int *temp)
        {
            if(((arr[1]==arr[2])&&(arr[1]==arr[3]))||
               ((arr[1]==arr[5])&&(arr[1]==arr[9]))||
               ((arr[1]==arr[4])&&(arr[1]==arr[7])))
               {
                printf("The winner is the player using %c",arr[1]);
                *temp=0;
               }

            else if(((arr[2]==arr[5])&&(arr[2]==arr[8]))||
               ((arr[3]==arr[5])&&(arr[5]==arr[7]))||
               ((arr[4]==arr[5])&&(arr[5]==arr[6])))
               {
                printf("The winner is the player using %c",arr[5]);
                *temp=0;
               }

            else if(((arr[3]==arr[9])&&(arr[6]==arr[9]))||
                ((arr[7]==arr[9])&&(arr[8]==arr[9])))
                {
                 printf("The winner is the player using %c",arr[9]);
                 *temp=0;
                }
        }

int search(int x,int *array,int n)
{
    int q;
      for(q=0;q<n;q++)
      {
          if(array[q]==x)
          {
              return 0;
          }
          else
            continue;
      }
      return 1;
}
