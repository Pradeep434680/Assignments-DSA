// question -7
// high priority =>3
// medium priority =>2
//low priority=>1
#include<iostream>
using namespace std;
struct Element
{
    int val;
    int pri;
};
struct Queue
{
    Element * hp;
    Element * mp;
    Element * lp;
    int hf,mf,lf;
    int hr,mr,lr;
    int hs,ms,ls;
    public:
    void create(int hs,int ms,int ls);
    void push(Element E);
    void dispaly();
    int pop();

};



void Queue::create(int hs,int ms,int ls)
{
    hp = new Element[hs];
    mp = new Element[ms];
    lp = new Element[ls];
    hf=mf=lf=hr=lr=mr= -1;
    this->hs= hs;
    this->ms = ms;
    this->ls = ls;

};
void Queue::push(Element E)
{
    if(E.pri == 3)
    {
        if(hr == hs-1)
        {
            cout<<"queue is full\n";
            return;
        }
        if(hf == -1)
        {
            hf =hr =0;
            hp[hf] = E;
            return;
        }
        hr++;
        hp[hr]= E;

    }

        





    else if(E.pri==2)
    {
            if(mr == ms-1)
            {
                cout<<"queue is full\n";
                return;
            }
            if(mf == -1)
            {
                mf =mr =0;
                mp[mf] = E;
                return;
            }
            mr++;
            mp[mr] = E;
    }
       

       
    else
    {
        if(lr == ls-1)
        {
            cout<<"queue is full\n";
            return;
        }
        if(lf == -1)
        {
            lf =lr =0;
            lp[lf] = E;
            return;
        }
        lr++;
        lp[lr] =E;

    }

}

int Queue::pop()
{
    if(hf!=-1 && hf <= hr)
    {
        int x = hp[hf].val;
        hf++;
        if(hf >hr) hf=hr=-1;
        
        return x;
    }else if (mf != -1 && mf<= mr)
    {
        int x =  mp[mf].val;
        mf++;
        if ( mf>mr)mf=mr=-1;
        return x;
    }
    else if( lf != -1 && lf<= lr)
    {
        int x = lp[lf].val;
        lf++;
        if(lf>lr)lf=lr=-1;
        return x;
    }
    else {
        cout<<"queue is empty\n";
        return -1;
    }

}

          
    
 
        

void Queue::dispaly()
{
    for(int i= hf; i<=hr; i++)
    {
        cout<<"("<<hp[i].val<<","<<hp[i].pri<<")"<<endl;
    }
    for(int i= mf; i<=mr; i++)
    {
        cout<<"("<<mp[i].val<<","<<mp[i].pri<<")"<<endl;
    }
    for(int i= lf; i<=lr; i++)
    {
        cout<<"("<<lp[i].val<<","<<lp[i].pri<<")"<<endl;
    }
}





    
int main()
{
     Queue q;
     int h;
     int m;
     int l;
     cout<<"enter the value of vips:";
     cin>>h;
     cout<<"enter the number of normal:";
     cin>>m;
     cout<<"enter the value of low:";
     cin>>l;
     q.create(h,m,l);

    Element e1;
    e1.pri = 3;
    e1.val=5;
    Element e2;
    e2.pri = 3;
    e2.val=10;
    Element e3;
    e3.pri = 1;
    e3.val=1;
    Element e4;
    e4.pri=2;
    e4.val=2;
    Element e5;
    e5.pri =2;
    e5.val=21;
    Element e6;
    e6.pri=1;
    e6.val =10;
    q.push(e1);
    q.push(e3);
    q.push(e2);
    q.push(e5);
    q.push(e4);
    q.push(e6);
    q.dispaly();

    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;

    q.push(e4);
    cout<<q.pop()<<endl;

 

    q.dispaly();
}

// output
/*
enter the value of vips:4
enter the number of normal:4
enter the value of low:4
(5,3)
(10,3)
(21,2)
(2,2)
(1,1)
(10,1)
5
10
21
2
1
10
queue is empty
-1
2*/