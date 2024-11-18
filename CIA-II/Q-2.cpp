// selection sort
#include<iostream>
using namespace std;
void selection_sort(int arr[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        // this is the index of that element that will be swap with the smallest element
        //in remaining array
        int index = i;
        for(int j= i+1; j<n; j++)
        {
            if(arr[j]<arr[index])
            {
                index = j;
            }
            // swapping
                int temp = arr[i];
                arr[i] =arr[index];
                arr[index] = temp;       
         }
    }
}
int main()
{
    int arr[]={5,2,7,4,1,9,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

}