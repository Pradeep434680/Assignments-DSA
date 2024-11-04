#include <iostream>
#include <queue>
using namespace std;


struct Node {
    int data;           
    Node* child;      
    Node* sibling;     


    Node(int d) {
        data = d;
        child = NULL;
        sibling = NULL;
    }
};


struct Tree {
    Node* root;  

    
    Tree() {
        root = NULL;
    }


    void create(int d) {
        if (root == NULL) {
            root = new Node(d);
            cout << "root Node created -> data is: " << d << endl;
        } else {
            cout << " already exists!" << endl;
        }
    }

    
    void insert_child(int parentData, int childData) {
        Node* parentNode = search(root, parentData); 
        if (parentNode) {
            Node* newNode = new Node(childData);
            if (!parentNode->child) {
                parentNode->child = newNode;  
            } else {
                Node* temp = parentNode->child;
                while (temp->sibling) {
                    temp = temp->sibling;  
                }
                temp->sibling = newNode;  
            }
            cout << "child " << childData << " : parent " << parentData << endl;
        } else {
            cout << "Parent node with data " << parentData << " not found." << endl;
        }
    }


    Node* search(Node* node, int data) {
        if (node == NULL) return NULL;
        if (node->data == data) return node;

        
        Node* found = search(node->child, data);
        if (found) return found;
        return search(node->sibling, data);
    }

    
    void display() {
        if (root == NULL) {
            cout << "there is no element present." << endl;
            return;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            Node* child = current->child;
            while (child) {
                q.push(child);
                child = child->sibling;
            }
        }
        cout << endl;
    }

    void insert() {
        int parentData, childData;
        cout << "enter the parent node: ";
        cin >> parentData;

        cout << "Enter the value of child node : ";
        cin >> childData;

        if (root == NULL) {
            create(parentData); 
            insert_child(parentData, childData);
        } else {
            insert_child(parentData, childData);
        }
    }
};

int main() {
    Tree t;
    t.create(1);           
    t.insert_child(2, 3);  
    t.insert_child(1, 3);  
    t.insert_child(2, 4);  
    t.insert_child(2, 5);  

    t.display();  

    t.insert();               
    t.insert();               
    t.insert();               
    t.insert();               
    t.display(); 
    return 0;
}
