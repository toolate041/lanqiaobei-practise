#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<cmath>
using namespace std;
const int N=1e3+10;
vector<int> p[N];
bool cursed[N];
void dfs(int pos)
{
  cursed[pos]=1;
  for(int i:p[pos])
  {
    if(cursed[i]==0)
    {
      cursed[i]=1;
      dfs(i);
    }
  }
}
double distance(double x,double y)
{
  return x*x+y*y;
}
int main()
{
  int i,j,n,m;
  int num;
  cin>>num;
  int circle;//表示传播的范围
  double x[1000]={0},y[1000]={0};
  for(i=0;i<num;i++)
  {
    cin>>n>>m;
    x[i]=n;
    y[i]=m;
  }
  cin>>circle;
  for(i=0;i<num;i++)
  {
    for(j=i+1;j<num;j++)
    {
      if(distance(x[j]-x[i],y[j]-y[i])<=circle*circle+1e-9)
      {
        p[i].push_back(j);
        p[j].push_back(i);
      }
    }
  }
  memset(cursed,0,sizeof(cursed));
  dfs(0);//从下标为0的地方输入数据，就从0开始dfs
  for(i=0;i<num;i++)
  {
    cout<<cursed[i]<<endl;
  }
}