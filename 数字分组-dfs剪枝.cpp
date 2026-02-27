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
    return true;
  }
  //枚举每个人所属的队伍
  for(i=1;i<=cnt;i++)
  {
    bool flag=false;
    for(auto &j:v[i])
    {
      if(a[dep]%j==0)
      {
        flag=true;
        break;
      }
    }//剪枝部分，提前判断是否有相同或倍数的数字存在
    if(flag)
    continue;
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
  sort(a+1,a+n+1);
  for(i=1;i<=n;i++)
  {
    if(dfs(i,1,n))
    {
      cout<<i<<endl;//对每一种分队方式判断其合法性，合法就输出
      return 0;//对于只输出一个答案的，要记得结束输出
    }
  }
}