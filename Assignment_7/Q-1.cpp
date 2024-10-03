// change a string into an integer
#include<iostream>

using namespace std;
int index=0;
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

   

int changeToint(string s,int arr[],string all_token[])
{
    
    string temp="";
    int i=0;
    int j=0;
    while(i<s.size())
    {
      
        if(s[i] == ' ')
        {
            all_token[j]= temp;
           
            parseToint(temp,index,arr);
            temp="";
            j++;
        }
        else
        {
            temp+= s[i];
        }
        i++;
    }

     if (!temp.empty()) {
        all_token[j] = temp;
        parseToint(temp, index, arr);
    }
    return j;
}
int main()
{
   string str;
    string all_token[20];
   int arr[10];
   cout<<"enter the string:";
   getline(cin,str); 
   int count =changeToint(str,arr,all_token);
//    cout<<index<<" ind";
    cout<<"all tokens\n";
        for(int j=0; j<=count; j++)
        {
            cout<<all_token[j]<<endl;
        }
        cout<<"string to int\n";
      for (int i = 0; i < index; i++) {
        if (arr[i] >= 0) {  // Print non-zero values
            cout << arr[i] << endl;
        }
        
    }


}


// enter the string:12 + 43 / 45 - 54 *
// all tokens
// 12
// +
// 43
// /
// 45
// -
// 54
// *
// string to int
// 12
// 43
// 45
// 54
