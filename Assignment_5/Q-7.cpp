//question 7
#include<iostream>
#include<cmath>
#include<map>
using namespace std;
#include "Q-6.cpp"


map<char, int> variableValues;

int evaluate_expression(string expression,operation *op)
{
    
    string ans =findProstfix(expression,op);
    int count=0;
    for(int i=0; i<ans.size(); i++)
    {
        if(ans[i]=='+' ||ans[i]=='-'|| ans[i]=='*' || ans[i]== '/' || ans[i]=='^')
        {
            continue;
        }
        else
        {
            count++;
        }
    }
    char variable;
    int value;
   
    for(int i=0; i<count; i++)
    {
        cout<<"enter the variable:";
        cin>>variable;
        cout<<"enter its value:";
        cin>>value;

        variableValues[variable] = value;
    }
    

    for(int i=0; i<ans.size(); i++)
    {
        cout<<ans[i];
    }
    cout<<endl;
    Stack st1;
 
    int result ;
    int first;
    int second;
    // now i have postfix expression in the ans;

    for(int i=0; i<ans.size(); i++)
    {
        if(ans[i]=='+' ||ans[i]=='-'|| ans[i]=='*' || ans[i]== '/' || ans[i]=='^')
        {
            if(variableValues[st1.peek()])
            first = variableValues[st1.peek()];
            else
            first = st1.peek()-'0';

            st1.pop();
            if(variableValues[st1.peek()])
            second =  variableValues[st1.peek()];
            else
            second = st1.peek()-'0';

            st1.pop();
            
            if(ans[i] == '+')
            result = second + first;
            else if(ans[i] == '-')
                result = second - first;
            else if(ans[i] == '*')
                result = second * first;
            else if(ans[i] == '/')
                result = second / first;
            else if(ans[i] == '^')
                result = pow(second, first); 

                st1.push(result + '0');
        }
        else
        {
            st1.push(ans[i]);
        }
    }

   return result;
}


// int main()
// {
    
//     operation *op = new operation();
//     op->create(10);
//     initialise(op);
//     string expression = "a+(c+(d+(e*f)))+(g*h)";
//     string ans =findProstfix(expression,op);
//     cout<<evaluate_expression(expression,op);
   
// }