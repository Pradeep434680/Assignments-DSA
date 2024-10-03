#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node * next;
    Node(int d)
    {
        data =d;
        next=NULL;
    }
};
class Hash
{
    Node **arr = new Node*[10];
    public:
    Hash()
    {
        for(int i=0; i<10; i++)
        arr[i]= NULL;
    }
    void insert(int d);
    bool search(int d);
};
void Hash::insert(int d)
{
    int index = d%10;
    Node * temp = new Node(d);
    if(arr[index]== NULL)
    {
        arr[index]  = temp;
        return;
    }
    Node *trav = arr[index];
    while(trav->next)
    {
        trav=trav->next;
    }
    trav->next = temp;
}
bool Hash::search(int d)
{
    int index = d%10;
    Node *trav = arr[index];
    while(trav)
    {
        if(trav->data==d)
        return 1;
        trav=trav->next;
    }
    return 0;

}
int main()
{
    Hash h;
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
0
1
0
1
1
*/