#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=2005;
int main()
{
  int n,V;//n种宝物，V是容量
  int v,w,s;
  int dp[N];
  memset(dp,0,sizeof(dp));
  cin>>n>>V;
  int i,j,k;
  for(i=0;i<n;i++)
  {
    cin>>v>>w>>s;
    for(j=V;j>=v;j--)
    {
      for(k=1;k<=s&&k*v<=j;k++)
      {
        dp[j]=max(dp[j],dp[j-k*v]+k*w);
      }
    }

  }
  cout<<dp[V]<<endl;
}
