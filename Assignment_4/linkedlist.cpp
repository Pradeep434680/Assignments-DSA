#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node * next;
};

Node * create(struct Node *N1,int x)
{
    Node * head = NULL;
    if(head==NULL)
    {
        head = new Node;
        head->data = x;
        head->next = NULL;
        
    }
    
    return head;
}

Node * insert_end(Node *head,int x)
{
    Node *temp;
    Node * tail=head;
    
    if(head)
    {
      while(tail->next)
      {
        tail = tail->next;
      }

      temp = new Node;
      temp->next = NULL;
      temp->data = x;
      tail-> next = temp;

    }else
    {
        head = create(head,x);
    }
    return head;

}

void display(Node *head)
{
        Node *temp = head;
        while(temp)
        {
            cout<<temp->data<<" ";
            temp =  temp->next;
        }
}