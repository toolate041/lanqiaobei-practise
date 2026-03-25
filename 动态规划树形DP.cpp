#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll=long long;
const int N=1e5+10;
vector<int> p[N];
int dp[N][2]={0};//用于计算最大利润，dp[i][0],表示不取i，dp[i][1]表示取i
int happy[N];
bool has_father[N]={false};
void dfs(int root)
{
  dp[root][1]=happy[root];
  for(int i:p[root])
  {
    dfs(i);
    dp[root][1]+=dp[i][0];//选了root就不能选i
    dp[root][0]+=max(dp[i][0],dp[i][1]);//不选root就要取下属的最大值
    //注意是要+=，利益是累加的
  }
}
int main()
{
  int n,i,j;
  int up,down;//up是上司，down是下属
  cin>>n;
  for(i=1;i<=n;i++)
  {
    cin>>happy[i];
  }
  for(i=0;i<n-1;i++)
  {
    cin>>down>>up;
    p[up].push_back(down);
    has_father[down]=true;
  }
  int root;
  for(i=1;i<=n;i++)
  {
    if(has_father[i]==false)
    {
      root=i;
      break;
    }
  }//找第一个不为0的作为根节点
  dfs(root);
  int maxnum=0;  
    for(j=1;j<=n;j++)
    {
      int m=max(dp[j][0],dp[j][1]);
      maxnum=max(m,maxnum);
    }
    cout<<maxnum<<endl;
}