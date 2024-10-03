#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node *next;
    public:
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};
class Queue
{
    Node * front;
    Node * rear;
    public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int d);
    int dequeue();
    int front_element();
    int size();
};
void Queue::enqueue(int d)
{
    if(front==NULL)
    {
        front = new Node(d);
        rear = front;
        cout<<d<<" is pushed\n";
        return;
    }
    rear->next = new Node(d);
    rear =rear->next;
    cout<<d<<" is pushed\n";
}

int Queue::dequeue()
{
    if(front == NULL)
    {
        rear = NULL;
        cout<<"queue is empty\n";
        return -1;
    }
    int x = front->data;
    Node * temp = front;
    front = front->next;
    delete temp;
    cout<<x<<" is poped \n";
    return x;

}
int Queue::front_element()
{
    return front->data;
}
int Queue::size()
{
    Node * temp= front;
    int count =0;
    while(temp != rear)
    {
        count++;
        temp = temp->next;
    }
    return count + 1;
}
int main()
{
    Queue q1;
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    cout<<"size of queue:"<<q1.size()<<endl;
    cout<<q1.front_element()<<endl;
    q1.enqueue(6);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    cout<<"size of queue:"<<q1.size()<<endl;
    cout<<q1.front_element()<<endl;
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.enqueue(4);
    cout<<q1.front_element()<<endl;


}
 
 // output
 
/*
1 is pushed
2 is pushed
3 is pushed
4 is pushed
5 is pushed
size of queue:5
1
6 is pushed
1 is poped
2 is poped
3 is poped
4 is poped
size of queue:2
5
5 is poped
6 is poped
queue is empty
4 is pushed
4*/