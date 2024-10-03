#include<iostream>
using namespace std;
struct Node
{
    char data;
    Node * next;
};
struct Stack
{
    private:
    int actual_size=0;
    
   
    Node * top = NULL;
    public:
    void create(char x);
    void push(char x);
    char pop();
    char peek();
    int size();
    bool isEmpty();

};
void Stack::create(char d)
{
    Node * temp = new Node;
    temp->data = d;
    temp->next = NULL;
    top = temp;
    actual_size=1;
    cout<<"created successfully\n";
    
}
void Stack::push(char x)
{
   
    Node *temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
    actual_size++;
    
}
char Stack::pop()
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
char Stack::peek()
{
    if(top == NULL)
    {
        cout<<"stack is empty\n";
        return '@';
    }
    return top->data;
}

bool Stack::isEmpty()
{
    if(actual_size ==0)
    return 1;
    else return 0;
}
int Stack::size()
{
    return actual_size;
}

