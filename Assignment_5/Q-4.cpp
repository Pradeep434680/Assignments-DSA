//question 4
#include<iostream>
using namespace std;
#include "stack.cpp"
bool checkParenthesis(string s)
{
    Stack s1;
    for(int i=0; i<s.size();i++)
    {
        if(s[i]=='{' || s[i]=='(' || s[i] =='[')
        {
            s1.push(s[i]);
        }
        else if(s[i] == '}' && s1.peek() !='{')
        {
            cout<<"not valid";
            return 0;
        }
        else if(s[i] == ')' && s1.peek() !='(')
        {
            cout<<"not valid";
            return 0;
        }
        else if(s[i] == ']' && s1.peek() !='[')
        {
            cout<<"not valid";
            return 0;
        }
        else if(s[i]==']' || s[i]==')' || s[i]=='}')
        s1.pop();

    }


    if(s1.isEmpty())
    {
        cout<<" brackets are valid\n";
        return 1;
    }
    else 
    {
        cout<<"brackets are not valid\n";
        return 0;
    }
}

// int main()
// {
//     string s = "{2+3}([7+{4+2}])}";
//     checkParenthesis(s);
    
// }