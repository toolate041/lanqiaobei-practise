#include<iostream>
#include<map>
using namespace std;
int main()
{
  char ch;
  string s;
  int i,j,n,m;
  map<char,int> p;
  cin>>s;
  for(char ch:s)
  {
    
    p[ch]++;
  }
  int maxcount=0;
  for(auto&it:p)//对p循环找最大的出现次数,这里的it相当与是指针
  {
    if(it.second>maxcount)
    {
      maxcount=it.second;
    }
  }
  for(auto&it:p)
  {
    if(it.second==maxcount)
    {
      cout<<it.first;
    }
  }
  cout<<endl;
}