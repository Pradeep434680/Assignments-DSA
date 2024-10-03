// question -9
#include<iostream>
using namespace std;
struct Patient
{
    string name;
    int age;
    string condition;
};
struct Queue
{
    Patient * normal;
    Patient * emergency;
    int nf,nr,ef,er;
    int ns,es;
    void create(int n,int m);
    void Enqueue();
    Patient Dequeue();
    Patient Peek();
    bool IsEmpty();
    void Display();
};
void Queue::create(int n,int m)
{
    normal = new Patient[n];
    emergency = new Patient[m];
    nf=nr=ef=er=-1;
    ns = n;
    es =m;

}
void Queue::Enqueue()
{
    Patient p;
    cout<<"enter the patient name:";
    cin>>p.name;
    cout<<"enter the age:";
    cin>>p.age;
    cout<<"enter the condition(normal/emergency):";
    cin>>p.condition;
    if(p.condition=="emergency")
    {
        if(er == es-1)
        {
            cout<<"there is not bed available!\n";
            return ;
        }
        if(ef==-1)
        {
            ef=er=0;
            emergency[ef] = p;
        }
        else
        {
            er++;
            emergency[er]= p;
          
        }
    }
    else if(p.condition=="normal")
    {
        if(nr == ns-1)
        {
            cout<<"there is not bed available!\n";
            return ;           
        }
        if(nf==-1)
        {
            nf=nr=0;
            normal[nr] = p;
            
        }else
        {
            nr++;
            normal[nr]= p;

        }
    }
                        
          
};

Patient Queue::Dequeue()
{
     Patient x;
     Patient dummy={"", 0, ""};
    if(ef!=-1 && ef<= er)
    {
       x = emergency[ef];
        ef++;
        if(ef>er)
        {
            ef=er=-1;
        }
        return x;
    }
    else if(nf != -1 && nr >= nf)
    {
             x =normal[nf];
            nf++;
            if(nf>nr)
            {
                nf=nr=-1;
            }
        return x;
    }
    else
    {
        cout<<"queue is empty\n";
        return dummy;
    }
    
}
Patient Queue::Peek()
{
    
    if( (ef != -1 && nf != -1)  && (ef + 1 <= er || ef <= er))
    {
       if(ef + 1 <= er )
       return emergency[ef+1];
       else if(ef<= er )
       {
        return normal[nf];
       }
    }
    else if(nf != -1 && nf+1 <= nr)
    {
        return normal[nf+1];
        
    }
    else
    {
        
         Patient dummy={"", 0, ""};
         return dummy;
    }
}

bool Queue::IsEmpty()
{
    if(ef == -1 && nf == -1)
    {
        return 1;
    }
    else if(ef>er && nf>nr)
    {
        return 1;
    }
    else
    return 0;
}
void Queue::Display()
{
    for(int i = ef; i<=er; i++)
    {
        cout<<emergency[i].name<<"  age: "<<emergency[i].age<<"   condotion:"<<emergency[i].condition<<endl;
    }

    for(int i = nf; i<= nr; i++)
    {
        cout<<normal[i].name<<"  age: "<<normal[i].age<<"  condition :"<<normal[i].condition<<endl;
    }
}
int main()
{
    int n,m;
    cout<<"enter the capacity of normal patients:";
    cin>>n;
    cout<<"enter the capacity of emergency patients:";
    cin>>m;
    Queue q;
    q.create(n,m);
    q.Enqueue();
    q.Enqueue();
  
    cout<<"next patient:"<<q.Peek().name<<endl;
    cout<<q.Dequeue().name<<endl;
    cout<<"isempty:"<<q.IsEmpty();
    cout<<"nexy patient:"<<(q.Peek().name == ""?"none":q.Peek().name)<<endl;
    cout<<q.Dequeue().name<<endl;
    cout<<"isempty:"<<q.IsEmpty();
    cout<<q.Dequeue().name<<endl;

    q.Display();
}
