//question -5
#include<iostream>
using namespace std;
struct table
{
    char opr ;
    int pdc;
    bool asc;
};
struct operation
{
    private:
    table *data;
    int length;
    int size=1;
    public:
    void create(int n);
    void insert(table t);
    void display();
    int precedence(char c);
    int associativity(char c);
    void store_by_input();
    
};

int operation::precedence(char c)
{
    for(int i=0; i<size; i++)
    {
        if(data[i].opr == c)
        {
            return data[i].pdc;
        }
    }
    return -1;
}
int operation::associativity(char c)
{
    for(int i=0; i<size; i++)
    {
        if(data[i].opr == c)
        {
            return data[i].asc;
        }
    }
    return -1;
}

void operation::create(int n)
{
    data = new table[n];
    length = n;
    size =0;

};


void operation::insert(table t)
{
    
    // table t;
    // cout<<"enter "<<size+1<<"th operator details:\n";
    // cout<<"enter the operator:";
    // cin>>t.opr;
    // cout<<"enter the precedence:";
    // cin>>t.pdc;
    // cout<<"enter the associativity of operator:";
    // cin>>t.asc;
 
 
    if(size<=length)
    {
        data[size] = t;
        size++;
    }else{
        cout<<"size is full\n";
        return;
    }
}
void operation::store_by_input()
{
    table t;
    string s;
    do
    {
        cout<<"enter "<<size+1<<"th operator details:\n";
        cout<<"first operator details:";
        cout<<"enter the operator:";
        cin>>t.opr;
        cout<<"enter the precedence:";
        cin>>t.pdc;
        cout<<"enter the associativity of operator:";
        cin>>t.asc;
        data[size] = t;
        cout<<"Do you want to store Operator:(yes/no):";
        cin>>s;
        data[size] = t;
        size++;
       
    } while (s=="yes");
    

      

    
}
void operation::display()
{
    cout<<endl;
    for(int i=0; i<size; i++)
    {
        cout<<"operator:"<<data[i].opr<<" | "<< (data[i].asc ?" right to left ":" left to right ")<<"  |  precedence:"<<data[i].pdc<<endl;
    }
    cout<<endl;
}

// int main()
// {
    // operation op;
    // op.create(5);
    // table t1;
    // table t2;
    // table t3;
      
    // t1.opr ='-';
    // t1.asc = 0;
    // t1.pdc =1;
    
    // t2.opr ='*';
    // t2.asc = 0;
    // t2.pdc =2;
   
    // t3.opr ='/';
    // t3.asc = 0;
    // t3.pdc =2;
    // op.insert(t1);
    // op.insert(t2);
    // op.insert(t3);
    // op.display();
    
   

    
// }

