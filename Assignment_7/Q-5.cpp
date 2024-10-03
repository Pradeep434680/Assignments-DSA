// circular queue
#include<iostream>
using namespace std;
int count_size=0;
class Queue{
    private:
    int front;
    int rear;
    int size;
    int *arr;
    public:
    Queue(int n)
    {
        front=-1;
        rear=-1;
        size = n;
        arr= new int[n];
    }
    
    void enqueue(int d);
    int dequeue();
    int size_of_que();

};
void Queue::enqueue(int d)
{
    if(front==-1)
    {
        front =0;
        rear = 0;
        count_size++;
        arr[front] = d;
        
    }
    else
    {
        
        rear =( rear+1)%size; 
        if(front== rear)
        {
            cout<<"queue is full\n";
            rear--;
            return;
        }
        // rear =( rear+1)%size;
        count_size++;
        
        arr[rear]= d;

    }
    cout<<d <<" is pushed in to the queue\n";
}
int Queue::dequeue()
{
    if(front==-1)
    {
        cout<<"queue is empty\n";
        count_size=0;
        return -1;
    }
    
    int x= arr[front];
    
    if(front==rear)
    {
        front=rear=-1;
        cout<<"queue is empty\n";
        count_size=0;
        return -1;
    }
    front = (front+1)%size;
    count_size--;
    cout<<x<<" is poped from the queue\n";
    return x;
    
}
int Queue::size_of_que()
{
    return count_size;
}

int main()
{
    Queue q1(5);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(6);
    cout<<"size of :"<<q1.size_of_que()<<endl;
    q1.dequeue();
    q1.dequeue();
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    cout<<"size of :"<<q1.size_of_que()<<endl;
    q1.dequeue();
    q1.enqueue(3);
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    cout<<"size of :"<<q1.size_of_que()<<endl;
    q1.dequeue();
    q1.enqueue(2);
    q1.enqueue(2);
    q1.enqueue(2);
    q1.enqueue(2);
    cout<<"size of :"<<q1.size_of_que()<<endl;
    q1.dequeue();
    cout<<"size of :"<<q1.size_of_que()<<endl;
    
   




}

// output
/*
2 is pushed in to the queue
3 is pushed in to the queue
4 is pushed in to the queue
5 is pushed in to the queue
6 is pushed in to the queue
queue is full
size of :5
2 is poped from the queue
3 is poped from the queue
1 is pushed in to the queue
2 is pushed in to the queue
queue is full
size of :5
4 is poped from the queue
3 is pushed in to the queue
5 is poped from the queue
6 is poped from the queue
1 is poped from the queue
2 is poped from the queue
queue is empty
size of :0
queue is empty
2 is pushed in to the queue
2 is pushed in to the queue
2 is pushed in to the queue
2 is pushed in to the queue
size of :4
2 is poped from the queue
size of :3*/