#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N=100;
vector<int> v[N];//v[0]存储了第一队的所有成员，以此类推
int a[N];
bool dfs(int cnt,int dep,int n)
{
  int i,j,k;
  if(dep==n+1)
  {
    for(i=1;i<=cnt;i++)
    {
      for(j=0;j<v[i].size();j++)
      {
        for(k=j+1;k<v[i].size();k++)
        {
          if(v[i][k]%v[i][j]==0)
          return false;
        }
      }
    }
    return true;
  }
  //枚举每个人所属的队伍
  for(i=1;i<=cnt;i++)
  {
    v[i].push_back(a[dep]);
    if(dfs(cnt,dep+1,n))
    {
      return true;
    }
    v[i].pop_back();
  }
  return false;
}
int main()
{
  int i,j,n,k;
  cin>>n;
  for(i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  sort(a,a+n);
  for(i=1;i<=n;i++)
  {
    if(dfs(i,1,n))
    {
      cout<<i<<endl;//对每一种分队方式判断其合法性，合法就输出
    }
  }
}