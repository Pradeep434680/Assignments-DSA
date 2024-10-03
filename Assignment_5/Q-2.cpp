//assignment 5 question 2
#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
};
struct Stack
{
    private:
    int actual_size=0;
   
    Node * top=NULL;
    public:
    void create(int x);
    void push(int x);
    int pop();
    int peek();
    int size();
    bool isEmpty();

};
void Stack::create(int d)
{
    Node * temp = new Node;
    temp->data = d;
    temp->next = NULL;
    top = temp;
    actual_size=1;
    cout<<"created successfully\n";
    
}
void Stack::push(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
    actual_size++;
    cout<<x<<" pushed\n";
}
int Stack::pop()
{
    if(top == NULL)
    {
        cout<<"stack underflow\n";
        return -1;
    }
    Node * temp = top;
    int data = top->data;
    top = top->next;
    actual_size--;
    delete temp;
    return data;

}
int Stack::peek()
{
    if(top == NULL)
    {
        cout<<"stack is empty\n";
        return -1;
    }
    return top->data;
}

bool Stack::isEmpty()
{
    if(actual_size ==0 )
    return 1;
    else return 0;
}
int Stack::size()
{
    return actual_size;
}

int main()
{
    Stack s1;
    s1.create(4);
    s1.push(5);
    s1.push(6);
    cout<<(s1.pop())<<endl;
    cout<<s1.peek()<<endl;
    cout<<s1.isEmpty()<<endl;
    s1.pop();
   
    cout<<s1.size()<<endl;
}