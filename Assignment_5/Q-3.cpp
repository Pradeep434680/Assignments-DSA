//question 3
#include<iostream>
using namespace std;
struct Node
{
    char data;
    Node * next;
};
struct Stack3
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
void Stack3::create(int d)
{
    Node * temp = new Node;
    temp->data = d;
    temp->next = NULL;
    top = temp;
    actual_size=1;
    cout<<"created successfully\n";
    
}
void Stack3::push(int x)
{
    Node *temp = new Node;
    temp->data = x;
    temp->next = top;
    top = temp;
    actual_size++;
    
}
int Stack3::pop()
{
    if(top == NULL)
    {
        cout<<"Stack3 underflow\n";
        return -1;
    }
    Node * temp = top;
    int data = top->data;
    top = top->next;
    actual_size--;
    delete temp;
    return data;

}
int Stack3::peek()
{
    if(top == NULL)
    {
        cout<<"Stack3 is empty\n";
        return -1;
    }
    return top->data;
}

bool Stack3::isEmpty()
{
    if(actual_size ==0 )
    return 1;
    else return 0;
}
int Stack3::size()
{
    return actual_size;
}

int main()
{
    string s = "((a+b))-)(((()x+2)*4))";
    Stack3 s1;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i] == '(')
        {
            s1.push('(');
        }
        else if(s[i] ==')')
        {
            if(s1.size()==0)
            {
                cout<<"invalid paremthesis";
                return 0;
            }
            s1.pop();
        }
    }
    if(s1.isEmpty())
    {
        cout<<"valid parenthesis\n";
    }
    else{
        cout<<"invalid parenthesis\n";
    }
}