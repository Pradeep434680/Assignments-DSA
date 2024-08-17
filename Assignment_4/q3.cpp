// reverse  a linked list
#include<iostream>
using namespace std;
#include "linkedlist.cpp";
    Node* reverseList(Node* head) {
        Node * prev = NULL;
        Node * curr = head;
        Node * temp;
        if(head== NULL || head->next == NULL){

          return head;
        }
        while(curr){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr =temp;
           
        }
        
        
        return prev ;
        
    }


int main()
{
    Node N1;
    Node * head = NULL;
    head =create(&N1,3);
    insert_end(head,5);
    insert_end(head,1);
    insert_end(head,6);
    insert_end(head,4);
    // cout<<head;

    head = reverseList(head);
    display(head);
    

}