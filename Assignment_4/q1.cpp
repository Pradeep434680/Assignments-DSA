#include<iostream>
using namespace std;
int max_pow2  =0;

struct Node
{
    int data;
    Node * next;

};

Node * create_poly(int max_pow,struct Node *N)
{
    struct Node * head = NULL;
    struct Node * temp;
    struct Node * curr;
    int data;
    int n =max_pow;
    n++;

    while(n--)
    {
        cout<<"enter the coefficient of x^"<<n;
        cin>>N->data;
        if(head == NULL)
        {
            head = new Node;
            head->data = N->data;
            head->next = NULL;
            curr = head;
        }
        else
        {
            temp = new Node;
            temp->data = N->data;
            temp->next = NULL;
            curr->next = temp;
            curr=curr->next;

        }
        
    }
    return head;
}

void display_poly(Node * head,int max_power)
{
    int count_pow = max_power;
    while(head)
    {
        cout<<head->data<<"X^"<<count_pow;
        head= head->next;
        count_pow--;
        if(count_pow != -1)
        {
            cout<<" + ";
        }
    }
}
Node * add_polynomial( Node *head1, struct Node N2,int max_pow1)
{
    Node * head = NULL;
    Node * curr = NULL;
    Node * head2;
    
    cout<<"Enter the max power of second poly:";
    cin>>max_pow2;
    int sec_pow = max_pow2;
    // cout<<"curr value of :"<<max_pow2<<endl;
     head2 = create_poly(sec_pow,&N2);

    while( head1 && head2)
    {
        if(max_pow1 > sec_pow)
        {
            if(head == NULL)
            {
                head = new Node;
                head->data = head1->data;
                head->next =NULL;
                curr = head;
            }else
            {
                Node * temp = new Node;
                temp->data = head1->data;
                curr->next = temp;
                temp->next = NULL;
                curr= curr->next;
            }
            head1 = head1->next;
            max_pow1--;
        }
        else if(sec_pow>max_pow1)
        {
             if(head == NULL)
            {
                head = new Node;
                head->data = head2->data;
                head->next =NULL;
                curr = head;
            }
            else
            {
                Node * temp = new Node;
                temp->data = head2->data;
                curr->next = temp;
                temp->next = NULL;
                curr= curr->next;
            }
                sec_pow--;
                head2= head2->next;
        }
        else
        {
             if(head == NULL)
            {
                head = new Node;
                head->data = head1->data + head2->data;
                head->next =NULL;
                curr = head;
               
            }
            else
            {
                Node * temp = new Node;
                temp->data = head1->data + head2->data;
                curr->next = temp;
                temp->next = NULL;
                curr= curr->next;
            }
             head1= head1->next;
            head2= head2->next;
                

        }
    }
    return head;
}

int main()
{
    
    Node N1;
    Node N2;
    Node * head;
    int max_pow;
    cout<<"Enter the value of highest power of x:";
    cin>>max_pow;
    head=create_poly(max_pow,&N1);
    // cout<<head;
    // display_poly(head,max_pow);
    head =add_polynomial(head,N2,max_pow);
  
    display_poly(head,max_pow>max_pow2?max_pow:max_pow2);
}