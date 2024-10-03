// quesrion -1
#include<iostream>
using namespace std;
class Hash
{
    int size;
    int *arr;
    public:
    Hash(int s)
    {
        arr= new int[s+1];
        size=s+1;// because the size of arr is 10(max element) and i want to store 10 then 10%10 =0;but 10%11 =10 th index
        for(int i=0; i<size; i++)
        arr[i]=-1;
    }
    void insert(int d);
    bool search(int d);
};

void Hash::insert(int d)
{
    arr[d]= d;
};
bool Hash::search(int d)
{
    if(arr[d] == d)return 1;
    else return 0;
}
int main()
{
    int n;
    cout<<"enter the largest value that you want to store:";
    cin>>n;
    Hash h(n);
    h.insert(5);
    h.insert(0);
    h.insert(15);
    h.insert(98);
    h.insert(67);
    h.insert(14);
    h.insert(29);
    h.insert(18);
    h.insert(63);
    h.insert(3);
    h.insert(8);
    cout<<h.search(2)<<endl;
    cout<<h.search(18)<<endl;
    cout<<h.search(65)<<endl;
    cout<<h.search(8)<<endl;
    cout<<h.search(0)<<endl;
    return 0;
}

//output
/*
enter the largest value that you want to store:98
0
1
0
1
1
*/

