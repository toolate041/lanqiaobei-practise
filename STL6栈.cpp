#include<iostream>
#include<stack>
using namespace std;
int main()
{
  int i,j,n,m;
  char ch;
  stack<char> p;
  cin>>n;
  int flag=0;
  while(n--)
  {
    cin>>ch;
    if(ch=='(')
    {
      p.push(ch);
    }
    else if(ch==')'&&!p.empty())
    {
      p.pop();
    }
    else 
    {
      cout<<"No"<<endl;
      flag=1;
      break;
    }
  }
  if(p.empty()&&!flag)
  {
    cout<<"Yes"<<endl;
  }
  else if(!p.empty()&&!flag)
  {
    cout<<"No"<<endl;
  }
}