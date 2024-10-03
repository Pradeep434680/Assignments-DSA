// assignment 5 question 1
#include<iostream>
using namespace std;
struct Stack
{
    private:
    int index;
    int total_size;
    int *Arr;
    public:
    void create(struct Stack *s1,int n);
    void push(struct Stack *s1,int n);
    int pop(struct Stack *s1);
    int peek(struct Stack *s1);
    bool isEmpty(struct Stack *s1);
    int size(struct Stack *s1);
    
};
void Stack::create(struct Stack *s1,int n)
{
    s1->total_size = n;
    s1->index = -1;
    s1->Arr = new int[n];
}
void Stack::push(struct Stack *s1,int x)
{
    
    s1->index++;
    if(s1->index ==s1->total_size)
    {
        cout<<"stack overflow\n";
        return;
    }
    s1->Arr[s1->index] = x;
    cout<<x<<" is pushed into the stack\n";
}
int Stack::pop(struct Stack *s1)
{
    if(s1->index  == -1)
    {
        cout<<"stack underflow\n";
        return -1;
    }
    s1->index--;
    return s1->Arr[s1->index +1];
}
int Stack::size(struct Stack *s1)
{
    return s1->index+1;
}
int Stack::peek(struct Stack *s1)
{
    
    return s1->Arr[s1->index];
}
bool Stack::isEmpty(struct Stack *s1)
{
    if(s1->index==-1)return 1;
    else return 0;
}
int main()
{
    Stack s1;
    int n;
    cout<<"enter the size of stack:";
    cin>>n;
    s1.create(&s1,n);
    s1.push(&s1,1);
    s1.push(&s1,2);
    s1.push(&s1,3);
    s1.push(&s1,4);
    s1.push(&s1,5);
    cout<<s1.pop(&s1)<<endl;
    cout<<s1.pop(&s1)<<endl;
    cout<<s1.size(&s1)<<endl;
    cout<<s1.peek(&s1)<<endl;
    cout<<s1.isEmpty(&s1);
}
    

   

