#include<stdio.h>
int binarySearch(int arr[],int l,int r,int x);
int main()
{
    int arr[10],i,search,n,position;
    printf("How many elements: ");
    scanf("%d",&n);
    printf("Enter the array elements in a sorted manner:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element which you want to search: ");
    scanf("%d",&search);
    position=binarySearch(arr,0,n-1,search);
    (position==-1)?printf("Search Unsuccessful"):printf("%d is found in position=%d",search,position);
    return 0;
}
int binarySearch(int arr[],int f,int l,int x)
{
    int mid=(f+l)/2;
    if(arr[f]<arr[l])
    {
        if(f<=l)
        {
            if(arr[mid]==x)
                return mid;
            else if(arr[mid]<x)
                return binarySearch(arr,mid+1,l,x);
            else
                return binarySearch(arr,f,mid-1,x);
        }
        return -1;
    }
    else
    {
        if(f<=l)
        {
            if(arr[mid]==x)
                return mid;
            else if(arr[mid]>x)
                return binarySearch(arr,mid+1,l,x);
            else
                return binarySearch(arr,f,mid-1,x);
        }
        return -1;
    }
}
