//question -8
#include<iostream>
using namespace std;
#include<stack>

struct Queue
{
    private:
    stack<int>st1;
    stack<int>st2;
    public:
    bool empty();
    void push(int x);
    int pop();
    int peek();
};
bool Queue::empty() {
        if(st1.empty() && st2.empty())
        return 1;
        else return 0;
}

void  Queue::push(int x) {
    cout<<x<< "  pushed \n";
    st1.push(x);
}
int  Queue::pop() {
    int p;
    if(empty())
    {
        cout<<"queue is empty\n";
        return 0;

    }
    else if(!st2.empty())
    {
        p = st2.top();
        cout<<p<<" is poped\n";
        st2.pop();
        return p;
    }
    else 
    {
        while(!st1.empty())
        {
            st2.push(st1.top());
           
            st1.pop();
        }
        p = st2.top();
        st2.pop();
        cout<<p<<" is poped\n";
        return p;

    }
    

}
int  Queue::peek() {
    if(empty())
    return 0;
    else if(!st2.empty())
    {
        return st2.top();
    }
    else 
    {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }

        return st2.top();

    }
    
    
}
int main()
{
    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.peek()<<endl;


}

//output
/*
1  pushed 
2  pushed
3  pushed
4  pushed
5  pushed
6  pushed
1 is poped
2 is poped
3 is poped
4 is poped
5*/
    
    
    