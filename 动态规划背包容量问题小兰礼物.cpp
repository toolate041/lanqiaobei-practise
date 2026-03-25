#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1005;
int main()
{
  int V;
  int i,j,n,k;
  int num;//每个礼物的体积
  cin>>V>>n;
  int dp[N];
  memset(dp,-1,sizeof(dp));//要对数组使用memset进行复制-1，不能用{-1}
  dp[0]=0;
  for(i=0;i<n;i++)
  {
    cin>>num;
    if(num>V)
    continue;
    for(j=V;j>=num;j--)
    {
      if(dp[j-num]!=-1)
      dp[j]=dp[j-num]+num;
    }
  }
  int maxnum=0;
  for(i=0;i<=V;i++)
  {
    maxnum=max(maxnum,dp[i]);
  }
  cout<<V-maxnum<<endl;
}