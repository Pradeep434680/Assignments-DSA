#include<iostream>
using namespace std;
void parseToint(string temp,int &index,int arr[])
{
    
    
    int total_digit=0;
    for(int i=0; i<temp.size(); i++)
    {
        int digit = temp[i] -'0';
        total_digit = total_digit*10 + digit;
    }
    arr[index]= total_digit;
    index++;
}

   

void changeToint(string s,int arr[])
{
    int index=0;
    string temp="";
    int i=0;
    while(i<s.size())
    {
      
        if(s[i] == ' ')
        {
            parseToint(temp,index,arr);
            temp="";
        }
        else
        {
            temp+= s[i];
        }
        i++;
    }
     if (!temp.empty()) {
        parseToint(temp, index, arr);
    }
}
int main()
{
   string str;
   int index =0;
   int arr[10];
   cout<<"enter the string:";
   getline(cin,str); 
   changeToint(str,arr);
   cout<<index<<" ind";
      for (int i = 0; i < index; i++) {
        if (arr[i] != 0) {  // Print non-zero values
            cout << arr[i] << endl;
        }
    }


}
