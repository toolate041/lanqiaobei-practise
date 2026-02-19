#include<iostream>
using namespace std;
using ll=long long;
ll digui(ll num)
{
  ll res=0;
  if(!num)
  return 1;
  if(num%2==0)
  {
    return digui(num/2);
  }
  else
  {
    res+=digui(num-1)+1;
  } 
  return res;
}
int main()
{
  ll num;
  int i,j,n,m;
  cin>>num;
  cout<<digui(num)<<endl;
}
