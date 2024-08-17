#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node * next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node * create(Node * head,int x)
{
    if(head==NULL)
    {
        head = new Node(x);
    }
    return head;
}
 Node * insert_end(Node *head,int x)
{
    Node *temp = head;
    
    if(head)
    {
      while(temp->next)
      {
        temp = temp->next;
      }
      temp->next = new Node(x);

    }else
    {
        head = create(head,x);
    }
    return head;

}

   
Node * insert_begin(Node *head,int x)
{
    if(head==NULL)
    {
        head = create(head,x);
    }
    else
    {
        Node * temp = new Node(x);
        temp->next = head;
        head = temp;
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

void display_reverse(Node * head)
{
     int count =0;
    Node * temp = head;
    // if(temp == NULL || temp->next == NULL)
     if(temp == NULL)
    {
        cout<<"list doesn't exist\n";
    }
    while(temp->next)
    {
        count++;
        temp = temp->next;
    }
    int *arr = new int[count+1];
    temp = head;
    int index =0;
    while(temp)
    {
        arr[index] = temp->data;
        temp= temp->next;
        index++;
    }
    for(int i=index-1; i>=0; i--)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}



void reverse_linkedList(Node *head)
{
    int count =0;
    Node * temp = head;
    if(temp == NULL)
    {
        cout<<"list doesn't exist\n";
    }
    while(temp->next)
    {
        count++;
        temp = temp->next;
    }
    int *arr = new int[count+1];
    temp = head;
    int index =0;
    while(temp)
    {
        arr[index] = temp->data;
        temp= temp->next;
        index++;
    }
    temp = head;
    for(int i=index-1; i>=0; i--)
    {
        temp->data  = arr[i];
        temp = temp->next;
    }
    display(head);
    cout<<endl;

}
void search(Node *head,int x)
{
    Node * temp = head;
     if(temp == NULL)
    {
        cout<<"list doesn't exist\n";
    }else
    {
        int flag=0;
        while(temp)
        {
            if(temp->data == x)
            {
                cout<<x<<" is present in list\n";
                flag=1;
                break;
            }
            temp = temp->next;
        }
        if(flag==0)
        {
            cout<<x<<" doesn't present in list\n";
        }
        
    }

}

Node * merge(Node  * head1,Node * head2)
{
    if(head1 && head2)
    {
        Node * temp = head1;
        while(temp->next)
        {
            temp= temp->next;
        }
        temp->next = head2;
        return head1;
    }

    if(head1)
    return head1;
    else
    return head2;
};

Node* insert_in_sortedLinkedlist(Node * head,int x)
{
    Node *curr = head;

    if(x<head->data){
        Node * temp = new Node(x);
        temp->next=curr;
        head = temp;
        // return head;
    }else
    {
    while(curr->next)
    {
        if(curr->data >x)
        {
            break;
        }
        else{
            curr = curr->next;
        }
    }
    Node *future = curr->next;

    Node *temp = new Node(x);
    curr->next = temp;
    temp->next = future;

    }
    return head;
}

Node * sort_linkedList(Node * head)
{
    int count =0;
    Node * temp = head;
    if(temp == NULL)
    {
        cout<<"list doesn't exist\n";
    }
    while(temp->next)
    {
        count++;
        temp = temp->next;
    }
    int *arr = new int[count+1];
    temp = head;
    int index =0;
    while(temp)
    {
        arr[index] = temp->data;
        temp= temp->next;
        index++;
    }
    int min;
   for(int i=0; i<count; i++){
        min =arr[i];
        for(int j=i+1; j<count; j++){
            if(arr[j]<min)
            {
                int temp= arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                min = arr[i];
            }

        }
    }
      temp = head;
    for(int i=0; i<count; i++)
    {
        temp->data  = arr[i];
        temp = temp->next;
    }
    // display(head);

    return head;

}



int main()
{
    int x=2;
    int y =10;
    Node * head1 = NULL;
    Node * head2 = NULL;
    head1 = create(head1,x);
    insert_end(head1,3);
    insert_end(head1,4);
    insert_end(head1,5);
    insert_end(head1,6);
    // head1 = insert_in_sortedLinkedlist(head1,1);
    head1 = sort_linkedList(head1);
    display(head1);
    // reverse_linkedList(head1);
    // display(head1);
    // display(head1);
    // head1 = insert_begin(head1,7);
    // head1=insert_begin(head1,8);


    // head2 = create(head2,y);
    // insert_end(head2,12);
    // insert_end(head2,23);
    // head2 = insert_end(head2,33);
    // insert_end(head2,21);
    // head2 = insert_begin(head2,43);
    // head2=insert_begin(head2,32);
    // Node * head;
    // head = merge(head1,head2);
    // display_reverse(head);
    // search(head,61);
    // display(head);
    // reverse_linkedList(head);


    

return 0;
}