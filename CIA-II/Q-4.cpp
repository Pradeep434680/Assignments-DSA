//Quick sort
#include<iostream>
using namespace std;
int partition(int arr[],int start,int end)
{
    // this function will return the correct postion of the pivot element
    int position = start;
    for(int i = start; i<=end; i++)
    {
        // all element smaller then piovt element will come before pivot element
        if(arr[i]<=arr[end])
        {
            swap(arr[i],arr[position]);
            position++;
        }
    }
    return position -1;
}

void quick_sort(int arr[],int start,int end)
{
    if(start>=end)return;
    int pivot = partition(arr,start,end);
    // for left array
    quick_sort(arr,start,pivot-1);
    //for right array
    quick_sort(arr,pivot+1,end);
}
int main()
{
    int arr[]={5,2,7,4,1,9,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,n-1);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

}