       
 
#include<iostream>
using namespace std;
#include "linkedlist.cpp";
Node* middleNode(Node* head) {
        Node * fast = head;
        Node * slow = head;
         if(head->next==NULL){
            
            return head;
        }
        while(fast != NULL && fast->next != NULL){
           
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
int main()
{
    Node N1;
    Node * head = NULL;
    Node * middle;
    head =create(&N1,3);
    insert_end(head,2);
    insert_end(head,6);
    insert_end(head,8);
    insert_end(head,9);
    insert_end(head,10);
  
    // cout<<head;
    middle= middleNode(head);
    display(head);
    cout<<endl;
    display(middle);

}

   
    

    