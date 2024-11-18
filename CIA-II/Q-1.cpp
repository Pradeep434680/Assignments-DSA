// bubble sort
#include<iostream>
using namespace std;
void bubble_sort(int arr[],int n)
{
    for(int i=n-2; i>=0; i--)
    {
        // this will tell if any element is not swapped then break the loop 
        // because the array is already sorted
        bool swapped = false;
        for(int j=0; j<=i; j++)
        {
            if(arr[j]>arr[j+1])
            {
                // swapping
                int temp = arr[j];
                arr[j] =arr[j+1];
                arr[j+1] = temp;
                swapped= true;
            }
        }
        // not any swap then break the loop
        if (!swapped) 
        {
            break;
        }
    }
}
int main()
{
    int arr[]={5,7,1,9,3,4,6,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

}