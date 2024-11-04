#include<iostream>
using namespace std;
#include<stack>

class Node
{
    public:
    int data;
    Node * left ;
    Node * right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
Node * insert(Node *root,int d)
{
    if(!root)
    {
        Node * temp = new Node(d);
        return temp;
    }
    if(d<root->data)
    {
        root->left = insert(root->left,d);
    }
    else{
        root->right= insert(root->right,d);
    }
    return root;
}
bool search(Node *root, int d) {
    if (!root) return 0;
    if (root->data == d) return 1;

    if (d < root->data) {
        return search(root->left, d);
    } 
    else {
        return search(root->right, d);
    }
}




Node * delete_node(Node *root,int x)
{
    if(!root)return NULL;
    if(root->data>x)
    {
        root->left = delete_node(root->left,x);
        return root;
    }
    else if(root->data<x)
    {
        root->right = delete_node(root->right,x);
        return root;
        
    }
    else
    {
        // leaf node
        if(!root->left && !root->right)
        {
            delete root;
            return NULL;
        }
        // on child exist
        else if(!root->right)
        {
            Node * temp = root->left;
            delete root;
            return temp;
        }
        else if(!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        // both child exist
        else
        {
            Node * child = root->left;
            Node *parent = root;
            while(child->right)
            {
                parent = child;
                child = child->right;
            }
            if(root !=parent)
            {
                parent->right = child->left;
                child->left = root->left;
                child->right = root->right;
                delete root;
                return child;
            }
            child->right = root->right;
            delete root;
            return child;
        }
    }
}

void inorder_rec(Node * root)
{
    if(!root)return;

    inorder_rec(root->left);
    cout<<root->data<<"  ";
    inorder_rec(root->right);
}

void inorder_non_rec(Node* root) {
    stack<Node*> st;
    Node* current = root;

    while (current != NULL || !st.empty()) {
        while (current != NULL) {
            st.push(current);
            current = current->left;
        }

        current = st.top();
        st.pop();

        cout << current->data << " ";

        current = current->right;
    }
}
int main()
{
    Node * root = NULL;
    root=insert(root,4);
    root=insert(root,5);
    root=insert(root,14);
    root=insert(root,8);
    root=insert(root,34);
    root=insert(root,24);
    root=insert(root,3);
    root=insert(root,32);
    root=insert(root,2);
    root=insert(root,8);
    delete_node(root,8);
    delete_node(root,8);
    delete_node(root,14);
    inorder_non_rec(root);
    cout<<endl;
    inorder_rec(root);
    cout<<endl;
    cout<<search(root,8);
}