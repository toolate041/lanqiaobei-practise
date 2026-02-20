#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
using ll=long long;
const long long N=5e5+10;
int main()
{
  ll num,times;
  ll i,j,n,m;
  int first,end;
  ll  lightnum;
  ll light[N]={0};
  cin>>num>>times;
  ll diff[N]={0};
  ll prefix[N]={0};
  for(i=1;i<=num;i++)
  {
    cin>>light[i];
  }
  for(i=1;i<=num;i++)
  {
    diff[i]=light[i]-light[i-1];
  }
  while(times--)
  {
    cin>>first>>end>>lightnum;
    diff[first]+=lightnum;
    diff[end+1]-=lightnum;
  }
  for(i=1;i<=num;i++)
  {
    prefix[i]=prefix[i-1]+diff[i];
  }
  for(i=1;i<=num;i++)
  {
    if(prefix[i]<0)
    cout<<"0 ";
    else
    cout<<prefix[i]<<" ";
  }
  cout<<endl;
}
