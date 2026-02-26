#include<iostream>
using namespace std;
using ll=long long;
int n,answer=0;
const int N=1000;
int vis[N][N]={0};
void dfs(int dep)
{
  int i,j,k;
  if(dep==n+1)
  {
    answer++;
    return;
  }
  for(i=1;i<=n;i++)
  {
    if(vis[dep][i])
    continue;
    //修改数组
    for(j=1;j<=n;j++)
    {
      vis[j][i]++;
    }//那一列变为true
    for(j=dep,k=i;j>=1&&k>=1;j--,k--)vis[j][k]++;//左上角
    for(j=dep,k=i;j>=1&&k<=n;j--,k++)vis[j][k]++;//右上角
    for(j=dep,k=i;j<=n&&k>=1;j++,k--)vis[j][k]++;//左下角
    for(j=dep,k=i;j<=n&&k<=n;j++,k++)vis[j][k]++;//右下角
    dfs(dep+1);
    //恢复现场
    for(j=1;j<=n;j++)
    {
      vis[j][i]--;
    }
    for(j=dep,k=i;j>=1&&k>=1;j--,k--)vis[j][k]--;//左上角
    for(j=dep,k=i;j>=1&&k<=n;j--,k++)vis[j][k]--;//右上角
    for(j=dep,k=i;j<=n&&k>=1;j++,k--)vis[j][k]--;//左下角
    for(j=dep,k=i;j<=n&&k<=n;j++,k++)vis[j][k]--;//右下角

  }
}
int main()
{
  cin>>n;
  dfs(1);
  cout<<answer<<endl;
}