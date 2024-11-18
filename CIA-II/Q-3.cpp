// insertion sort
#include<iostream>
using namespace std;
void insertion_sort(int arr[],int n)
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        // it will only execute when the arr[j] > key
        // in sorted case it will help us to save the time
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main()
{
    int arr[]={5,24,7,6,9,1,4,2};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr,n);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

}

//output
PS C:\Users\Dell\Desktop\c++\Assignments\CIA-II> cd "c:\Users\Dell\Desktop\c++\Assignments\CIA-II\" ; if ($?) { g++ Q-3.cpp -o Q-3 } ; if ($?) { .\Q-3 }
1 2 4 5 6 7 9 24 