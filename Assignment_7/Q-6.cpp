//question 6
#include<iostream>
using namespace std;
struct Element
{
    int val;
    int pri;
};

struct Queue
{
    int front;
    int rear;
    int size;
    Element * arr;
    void create(int n);
    void push(Element A);
    void display();
    int pop();

};
void Queue::create(int n)
{
    front = -1;
    rear = -1;
    size = n;
    arr= new Element[n];

};
void Queue::push(Element E)
{
    if(rear == size-1)
    {
        cout<<"queue is full\n";
        return;
    }
    if(front == -1)
    {
        front =rear =0;
        arr[front] = E;
        return;
    }
    if(arr[rear].pri > E.pri)
    {
        rear++;
        arr[rear]=E;
        return;
    }
    

    int t = front;
    while(t<=rear)
    {
        if(arr[t].pri < E.pri)
        {
            int pos = t;
            int shift = rear;
            while(t<=rear)
            {
                arr[shift+1] = arr[shift];
                t++;
                shift--;
            }
            arr[pos] =  E;
            rear++;
            return;
        }
        else
        t++;
    }
}

int Queue::pop()
{
    if(front==-1)
    {
        cout<<"queue is empty\n";
        return -1;
    }
    if(front==rear)
    {
        int x= arr[front].val;
        front=rear=-1;
        return x;
    }

    int x= arr[front].val;
    front++;
    return x;

}
  

void Queue::display()
{
    for(int i=front; i<=rear; i++)
    {
        cout<<"("<<arr[i].val<<","<<arr[i].pri<<")"<<endl;
    }
}


int main()
{
    int n;
    Queue q;
    Element e1;
    e1.pri = 4;
    e1.val=5;
    Element e2;
    e2.pri = 3;
    e2.val=10;
    Element e3;
    e3.pri = 6;
    e3.val=1;
    Element e4;
    e4.pri=5;
    e4.val=2;
    Element e5;
    e5.pri = 10;
    e5.val=21;

    cout<<"enter the number of VIPs:";
    cin>>n;
    q.create(n);
    q.push(e2);
    q.push(e1);
    q.push(e3);
    q.push(e4);
    q.push(e5);
    q.display();
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    q.push(e1);
    cout<<q.pop()<<endl;
    q.push(e3);
    q.push(e4);
    


}
/*
(21,10)
(1,6)
(2,5)
(5,4)
(10,3)
21
1
2
queue is full
5
queue is full
queue is full*/



