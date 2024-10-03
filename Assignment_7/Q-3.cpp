//using single pointer
#include<iostream>
using namespace std;
class Queue
{
    private:
	int rear;
	int *arr;
	int size;
    public:
	Queue(int n)
	{
		size = n;
		arr = new int[n];
		rear = -1;
	}
	void enqueue(int d);
	int dequeue();
    int size_of_que();

};

void Queue::enqueue(int d)
{
	if(rear==-1)
	{
		rear =0;
		arr[rear] = d;
        cout<<d<<" is pushed in queue\n";
		return;
	}
	rear++;
	if(rear<size)
	{
		arr[rear] = d;
        cout<<d<<" is pushed in queue\n";
	}
	else
	{
        rear--;
	    cout<<"queue is full\n";
	}
}

int Queue::dequeue()
{
    if(rear == -1)
    {
        cout<<"queue is empty\n";
        return -1;
    }
        
   
	int x= arr[0];
	for(int i=1; i<=rear; i++)
	{
		arr[i-1] = arr[i];
	}
	rear--;

    cout<<x<<" is poped\n";
    return x;
}
int Queue::size_of_que()
{
    return rear + 1;
}

int main()
{
	Queue q1(5);
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(5);
    cout<<"size is:"<<q1.size_of_que()<<endl;
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    q1.dequeue();
    cout<<"size is:"<<q1.size_of_que()<<endl;
    q1.dequeue();
    q1.dequeue();
    q1.enqueue(3);
    q1.enqueue(4);
    cout<<"size is:"<<q1.size_of_que()<<endl;
    q1.dequeue();

	
}

//output


/*
1 is pushed in queue
2 is pushed in queue
3 is pushed in queue
4 is pushed in queue
5 is pushed in queue
queue is full
size is:5
1 is poped
2 is poped
3 is poped
4 is poped
size is:1
5 is poped
queue is empty
3 is pushed in queue
4 is pushed in queue
size is:2
3 is poped
*/
