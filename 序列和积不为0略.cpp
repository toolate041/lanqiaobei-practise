#include<iostream>
using namespace std;
int main()
{
  int i,j,t;
  int n,m,num;
  cin>>t;
  while(t--)
  {
    int a[1000];
    cin>>num;
    int count=0;
    int cnt=0;
    for(i=0;i<num;i++)
    {
      cin>>a[i];
      count+=a[i];
    }
    for(i=0;i<num;i++)
    {
      if(a[i]==0)
      {
        a[i]=1;
        count++;
        cnt++;
      }
    }
    if(!count)
    cout<<++cnt<<endl;
    else
    cout<<cnt<<endl;
  }
}