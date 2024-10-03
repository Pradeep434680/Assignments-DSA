// question-6

#include<iostream>
using namespace std;
#include "Q-4.cpp"
#include "Q-5.cpp"
string findProstfix(string s,operation *op)
{
    Stack st;
    string ans;
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]<='z' && s[i]>='a')
        {
            ans+= s[i];
        }
        else
        {
            if(st.isEmpty())
            {
                st.push(s[i]);
            }
            else
            {
                if(s[i]=='(')
                {
                    st.push(s[i]);
                }
                else if(s[i]==')')
                {
                    while(st.peek() != '(')
                    {
                        ans+= st.peek();
                        st.pop();
                    }
                    st.pop();
                }
                else if(op->precedence(s[i]) == op->precedence(st.peek()) && op->associativity(s[i]))
                {
                    st.push(s[i]);
                }
                 else if(op->precedence(s[i])> op->precedence(st.peek()))
                {
                    st.push(s[i]);
                }
                else
                {
                    while(!st.isEmpty() && op->precedence(s[i]) <= op->precedence(st.peek()))
                    {
                        ans+= st.peek();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
    }
    while(!st.isEmpty())
    {
        ans+= st.peek();
        st.pop();
    }
    return ans;
}
void initialise(operation *op)
{
    
    
    table t1;
    table t2;
    table t3;
    table t4;
    table t5;
    t1.opr ='-';
    t1.asc = 0;
    t1.pdc =1;
    t2.opr ='*';
    t2.asc = 0;
    t2.pdc =2;
    t3.opr ='/';
    t3.asc = 0;
    t3.pdc =2;
    t4.opr='^';
    t4.pdc=3;
    t4.asc =1;
    t5.opr ='+';
    t5.asc = 0;
    t5.pdc = 1;

    op->insert(t1);
    op->insert(t2);
    op->insert(t3);
    op->insert(t4);
    op->insert(t5);
    
}

// int main()
// {
    
    // operation *op;
    // op->create(10);
    // table t1;
    // table t2;
    // table t3;
    // table t4;
    // t1.opr ='-';
    // t1.asc = 0;
    // t1.pdc =1;
    // t2.opr ='*';
    // t2.asc = 0;
    // t2.pdc =2;
    // t3.opr ='/';
    // t3.asc = 0;
    // t3.pdc =2;
    // t4.opr='^';
    // t4.pdc=3;
    // t4.asc =1;

    // op->insert(t1);
    // op->insert(t2);
    // op->insert(t3);
    // op->insert(t4);
    // op->display();
    
      
//     string expression = "a+b*c-d^e^f+g";
//     string ans =findPrefix(expression,op);
//     for(int i=0; i<ans.size(); i++)
//     {
//         cout<<ans[i];
//     }

    
// }