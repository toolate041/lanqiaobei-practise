#include<iostream>
#include<string>
using namespace std;
const int N=1005;
int judge(int first,int last,int prefix[N])
{
  if(prefix[last]==prefix[first-1])
  {
    return last-first+1;
  }
  return -1;
}
int main()
{
  string s;
  int i,j,n,m;
  int a[N];
  int prefix[N]={0};
  prefix[0]=0;
  cin>>s;
  for(i=1;i<=s.length();i++)
  {
    if(s[i-1]=='L')
    {
      a[i]=1;
    }
    else
    {
      a[i]=-1;
    }
    prefix[i]=prefix[i-1]+a[i];
  }
  int max=0;
  for(i=1;i<=s.length();i++)
  {
    for(j=i;j<=s.length();j++)
    {
       int k=judge(i,j,prefix);
       if(k>max)
       {
        max=k;
       }
    }
  }
  cout<<max<<endl;
}
