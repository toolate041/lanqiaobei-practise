#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
using ll=long long;
const int N=105;

int main()
{
  int i,j,k;
  int n,V,M;//n是数量,V是书包体积，M是书包承受最大重量
  cin>>n>>V>>M;
  int v,m,s;//v体积,m质量,s价值
  int dp[N][N]={0};
  for(i=0;i<n;i++)
  {
    cin>>v>>m>>s;
    for(j=V;j>=v;j--)
    {
      for(k=M;k>=m;k--)
      {
        
        dp[j][k]=max(dp[j][k],dp[j-v][k-m]+s);
      }
    }
  }
  cout<<dp[V][M]<<endl;
}//二维背包从后向前遍历，跟自己和作差比大小取最大即可
