//question 8
#include<iostream>
using namespace std;
#include "Q-7.cpp"


int store_operands_value(char oper)
{
   return variableValues[oper];
}
int main()
{
    // check parenthesis balance

    // string s = "{2+3}([7+{4+2}])}";
    // checkParenthesis(s);
// to initialize the precedence table and insert other operators
    operation *op = new operation;
 
    op->create(10);// it will create 10 size that can store 10 operators
    initialise(op);// it will initilase the precedence table
    // op->store_by_input();// for input 
    // op->display();
    
 
// convert into postfix

    // string expression = "a+(c+(d+(e*f)))+(g*h)";
    // string ans =findProstfix(expression,op);
    // cout<<ans;

    // code for evaluate the expression
    // and will also take the value of operands from the user;

    // string expression = "a+(c+(d+(e*f+k)))+(g*h)";
    // string ans =findProstfix(expression,op);
    // cout<<evaluate_expression(expression,op)<<endl;



    cout<<store_operands_value('a');// value of operands 'a';
    
}