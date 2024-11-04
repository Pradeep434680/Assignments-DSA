#include<iostream>
#include<string.h>
using namespace std;
struct Node
{
    public:
    string name;
    string branch;
    string roll_no;
    Node *next;
    Node()
    {
        next =NULL;
    }
};
struct Hash
{
    public:
    Node **arr= new Node*[10];
    Hash()
    {
        for(int i=0; i<10; i++)
        arr[i]=NULL;
    }
    void insert();
    bool search(string s);

};

void Hash::insert()
{
    Node * student = new Node;
    cout<<"enter the name of student :";
    cin.ignore(); 
    getline(cin,student->name);
    cout<<"enter the roll-num of the student:(upperCase):";
    cin>>student->roll_no;
    cout<<"Enter the branch of student:";
    cin>>student->branch;


    int ascii=0;
    int count =0;
    for(int i=0 ; i<student->roll_no.size(); i++)
    {
        ascii += student->roll_no[i];
        count++;
    }
    if(count< 12)
    {
        cout<<"your roll_no is missing a letter:(may be zero)\n";
        return;
    }
    else if(count>12){
        cout<<"your roll_no has more than expected letter:";
        return;
    }

    
    int index = ascii % 10;
    if(arr[index]== NULL)
    {
        arr[index]  = student;
        return;
    }
    Node *trav = arr[index];
    while(trav->next)
    {
        trav=trav->next;
    }
    trav->next = student;

};
bool Hash::search(string roll)
{
    int ascii=0;
    int count =0;
    for(int i=0 ; i<roll.size(); i++)
    {
        ascii += roll[i];
        count++;
    }
   
    int index = ascii%10;
     Node *trav = arr[index];
    while(trav)
    {
        if(trav->roll_no==roll)
        return 1;
        trav=trav->next;
    }
    return 0;

}

int main()
{
   Hash h;
   h.insert();
   h.insert();
   h.insert();
   h.insert();
   h.insert();
   h.insert();
   cout<<h.search("2023BTCSE007");
   cout<<h.search("2023BTCSE0017");
   cout<<h.search("2023BTCSE002");
}

/*

enter the name of student :pradeep kumar
enter the roll-num of the student:(upperCase):2023BTCSE017
Enter the branch of student:CSE
enter the name of student :Rahul 
enter the roll-num of the student:(upperCase):2023BTCSE003
Enter the branch of student:cse
enter the name of student :Ammit 
enter the roll-num of the student:(upperCase):2023BTCSE028
Enter the branch of student:cse
enter the name of student :Gaurav
enter the roll-num of the student:(upperCase):2023BTCSE008
Enter the branch of student:ECE
enter the name of student :Punit
enter the roll-num of the student:(upperCase):2023BTCSE002
Enter the branch of student:BME
enter the name of student :yougesh
enter the roll-num of the student:(upperCase):2023BTCSE021
Enter the branch of student:cse
0
1
1*/