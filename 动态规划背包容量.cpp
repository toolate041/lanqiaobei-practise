#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
const int N=105,M=1005;
ll dp[N][M]={0};
int main()
{
  int num,V;//num表示有几个物品，V表示背包总体积
  cin>>num>>V;
  int i,j,w,v;//w是重量，v是每个物品的价值
  for(i=1;i<=num;i++)
  {
    cin>>w>>v;
    for(j=0;j<=V;j++)
    {
      if(j>=w)
      dp[i][j]=max(dp[i-1][j],dp[i-1][j-w]+v);
      else 
      dp[i][j]=dp[i-1][j];
    }
    //随着物品数量和包容量的增加，数据不断更新
    //对一个物品取或者不取，也就是取和不取求最大值，只要容量够肯定取，不够就不取
    //最后一个数就是最大值
  }
  cout<<dp[num][V]<<endl;
}