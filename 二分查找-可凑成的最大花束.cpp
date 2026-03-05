#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
using ll=long long;
int main ()
{
  int i,j;
  ll n,k;
  cin>>n>>k;//n是追求者数量，k是一束花有几朵
  ll ans=0;
  
  vector<ll> p(n);
  for(i=0;i<n;i++)
  {
    cin>>p[i];
  }
  if(n<k)
  {
    cout<<"0"<<endl;
    return 0;
  }
  ll left=0;
  ll right=0;
  int sum=0;
  for(ll g:p)
  {
    sum+=g;//这里的g就代表了p里的每个值
  }
  right=sum/k;
  ll total;
  while(left<=right)
  {
    ll mid=left+(right-left)/2;
    total=0;
    bool flag=false;
    for(i=0;i<n;i++)
    {
      total+=min(mid,p[i]);
      if(total>=mid*k)
      {
        flag=true;
        break;
      }
    }
    if(total>=mid*k)
    {
      ans=mid;
      left=mid+1;
    }
    else
    {
      right=mid-1;
    }//不断的逼近，最终left==right，二分法快速高效
  }
  cout<<ans<<endl;
}