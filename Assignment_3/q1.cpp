#include<iostream>
using namespace std;
int garbageVal=-9999;


struct Array
{
  int size=10;;
  int *arr;
  int index;
};

//Create an Array
void create(struct Array *A,int n)
{
   A->arr = new int[n];
   A->size= n;
   A->index = -1;
   cout<<"array is created successfully\n";
}

// get the current size of array
int sizeOfArr(Array *A)
{
  return A->index+1;
}

// display Array
void display(Array *A)
{
  if(!sizeOfArr(A)){
    cout<<"array is empty:)\n";
  }
  for(int i=0; i<=A->index; i++)
  {
    cout<<A->arr[i]<<"  ";
  }
  cout<<endl;
}


//Add any element in the last of Array
void add(struct Array *A,int n)
{
  if(A->index == A->size-1)
  {
    cout<<"array size is full\n";
    return;
  }
  else
  {
      A->index++;
      A->arr[A->index] = n;
      cout<<n<<" is inserted into the array in last\n";
  }
}

// delete an element from the last
void deleteFromLast(Array *A)
{
   if(A->index==-1)
   {
    cout<<"Array is empty already\n";
    return ;
   }
   else
   {
      cout<< A->arr[A->index]<<" is deleted from the last\n";
      A->arr[A->index] = garbageVal;
      A->index--;
      
   }
}

//delete an element from a particular position
void deleteElement(Array *A,int position)
{
    if(position == sizeOfArr(A)-1)
    {
      deleteFromLast(A);
    }
    else
    {
      if(position>A->size  || position<0)
      {
        cout<<"Beyond the range\n";
        return;
      }
    

      if(A->arr[position] == garbageVal || position >= sizeOfArr(A))
      {
        cout<<"at "<<position<<" this index no element is present for delete\n";
        return ;
      }
      else
      {
      cout<<A->arr[position]<<" is deleted from the array\n";
      A->index--;

      }
      for(int i= position; i<sizeOfArr(A); i++)
      {
       A->arr[i] = A->arr[i+1];
      }
      A->arr[A->index+1] = -9999;
    }
}

// insert any element at any particular position
void insert(Array *A,int position,int n)
{
  if(position == sizeOfArr(A))
  {
    add(A,n);
  }
  if(!sizeOfArr(A))
  {
    cout<<"array is empty :)\n";
    return;
  }
  else
  {
    if(position > A->size){
      cout<<"beyond the limit \n";
      return;
    }
    if(A->index +1 < position)
    {
      cout<<A->index<<" is the last index. you can't add at "<<position<<"th index\n";
      return;
    }else if(position<0)
    {
      cout<<"index of array start with 0 \n";
      return;
    }
    if(sizeOfArr(A)<A->size)
    {
      for(int i=sizeOfArr(A); i>position; i--)
      {
        A->arr[i] = A->arr[i-1];
      }

      A->arr[position] = n;
      cout<<n<<" is inserted at index "<<position<<endl;
      A->index++;
    }
  }
    
}

// calculate the avg of array
void CalAvg(Array *A)
{
  if(sizeOfArr(A) == 0){
    cout<<"array is empty :)\n";
    return ;
  }
  int count =0;
  int sum =0;
  for(int i=0; i<sizeOfArr(A); i++)
  {
    sum += A->arr[i];
    count++;
  }

  cout<< (float)sum/count<<" is the avg of Array";
  
}

// sort the array
void sortArray(Array *A)
{

  int n= A->size;
  if(n<=1)return;
  int min;
   for(int i=0; i<n; i++){
        min =A->arr[i];
        for(int j=i+1; j<n; j++){
            if(A->arr[j]<min)
            {
                int temp= A->arr[i];
                A->arr[i] = A->arr[j];
                A->arr[j] = temp;
                min = A->arr[i];
            }

        }
    }
}

// find minimum element of the array
void findMin(Array *A)
{
  int n= A->size;
  int min = A->arr[0];
  for(int i=1; i<n; i++)
  {
    if(min>A->arr[i]){
      min = A->arr[i];
    }
  }
  cout<<"Minimum element of the array is:"<<min<<endl;

}
// find the maximum element of the array

void findMax(Array *A)
{
  int n= A->size;
  int max = A->arr[0];
  for(int i=1; i<n; i++)
  {
    if(max<A->arr[i]){
      max = A->arr[i];
    }
  }
  cout<<"Maximum element of the array is:"<<max<<endl;

}

int main()
{
  Array A;
  struct Array * p =&A;
  create(p,7);
  add(p,8);
  add(p,2);
  add(p,7);
  add(p,1);
  add(p,9);
  add(p,13);
  add(p,3);
  // display(p);
  sortArray(p);
  display(p);
  
  

 
}
  