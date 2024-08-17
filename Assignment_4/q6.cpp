#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev = NULL;
    Node * next = NULL;
};

Node*  create(int x)
{
    Node * head= NULL;
    if(head == NULL)
    {
        head = new Node;
        head->data = x;
    }
    cout<<"created successfully\n";
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

Node* insert_in_end(Node * head,int x)
{
    Node *temp;
    Node *rare=head;
    
    if(head)
    {
      while(rare->next)
      {
        rare = rare->next;
      }

      temp = new Node;
      temp->data = x;
      rare-> next = temp;
      temp->prev = rare;
     

    }else
    {
        head = create(x);
    }
    return head;

}

Node * insert_begin(Node *head,int x)
{
    if(head==NULL)
    {
        head = create(x);
    }
    else
    {
        Node * temp = new Node;
        temp->data = x;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    return head;
}


Node* insert_in_sortedLinkedlist(Node * head,int x)
{
    Node *curr = head;
    Node *last = NULL;

    if(x<head->data){
        head=insert_begin(head,x);

        // return head;
    }
   
    else
    {
    while(curr->next)
    {
        if(curr->data >x)
        {
            break;
        }
        else{
            last = curr;
            curr = curr->next;
        }
    }

    if(curr->next == NULL)
    {
        head = insert_in_end(head,x);
    }else{
    Node *future = curr->next;

    Node *temp = new Node;
    temp->data=x;
    last->next  = temp;
    temp->prev =last;
    temp->next = curr;
    curr->prev = temp;

    }


    }
    return head;
}

Node * reverse(Node*head)
{
    if(head == NULL || head->next == NULL)
    return head;

    Node * curr,*last,*future;
    curr = head;
    last = NULL;
    future =NULL;

    while(curr)
    {
        future = curr->next;

        curr->next = last;
        curr->prev = future;

        last = curr;
        curr=future;
       
    }
    return last;
}

bool search(Node * head,int x)
{
    if(head == NULL)
    return 0;
   Node*curr = head;
    while(curr)
    {
        if(curr->data == x)
        return 1;
        curr=curr->next;
    }
    return 0;
    
}
int main()
{
    Node * head = NULL;
    Node*rare = NULL;
    // head = create(5);

    head= insert_begin(head,5);
    head= insert_begin(head,4);
    head= insert_in_end(head,6);
    head=insert_in_end(head,8);
    head= insert_in_end(head,10);
   head = insert_in_sortedLinkedlist(head,1);
   head = insert_in_sortedLinkedlist(head,7);
//    head = insert_in_sortedLinkedlist(head,11);
//    head = reverse(head);
cout<<search(head,1)<<endl;
//    head = insert_in_sortedLinkedlist(head,12,rare);

  display(head);

}