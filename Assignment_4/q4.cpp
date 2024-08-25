// reverse  a linked list
#include<iostream>
using namespace std;
#include "linkedlist.cpp";

 Node* deleteDuplicates(Node* head) {
        if(!head || !head->next)return head;
        Node* curr= head->next;
        Node* prev = head;
        while(curr){
            if(prev->data != curr->data){
                prev= prev->next;
                
            }
            else{
                prev->next= curr->next;
                delete curr;
            }
            curr= prev->next;
        }
        return head;

    }

int main()
{
    Node N1;
    Node * head = NULL;
    head =create(&N1,3);
    insert_end(head,3);
    insert_end(head,4);
    insert_end(head,4);
    insert_end(head,4);
    insert_end(head,6);
    insert_end(head,6);
    // cout<<head;
    head= deleteDuplicates(head);
    display(head);

}

   
    
