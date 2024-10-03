#include<iostream>
#include<string>
using namespace std;
struct expression
{
	string * data;
	int length;
};
void split_string(string s,expression * exp)
{
	int i=0; int j=0;
	string temp;
	while(i<s.size())
	{
		if(s[i] == ' ')
		{
			exp->data[j] = temp;
			j++;
			temp = "";
		}
		else
		{
			temp += s[i];
		}
		i++;
	}
	exp->length = j+1;
	
}
int main()
{
	string str;
	cout<<"enter the expression :";
	getline(cin,str);
	expression a;
	split_string(str,&a);
	for(int i=0; i<a.length; i++)
	{
		cout<<a.data[i]<<endl;
	}
}