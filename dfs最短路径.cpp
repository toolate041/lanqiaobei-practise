#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+10;
int m;
vector<int> p[N];
int ans=0;//ans表示路径的长度
int minnum=1000;
bool vis[N];
void dfs(int start,int final,int current)
{
  int i,j,n,m;
  if(current==final)
  {
    minnum=min(minnum,ans);
    return;
  }
  for(int &i:p[current])
  {
    if(vis[i])continue;
    vis[i]=true;
    ans++;
    dfs(start,final,i);
    vis[i]=false;
    ans--;//ans同样需要回溯，记得！
  }
  
}

int main()
{
  int i,j,n,g,h;
  int start,final;
  cin>>n>>m;
  for(i=1;i<=m;i++)
  {
    cin>>g>>h;
    p[g].push_back(h);
    p[h].push_back(g);
  }
  cin>>start>>final;
  memset(vis,0,sizeof(vis));
  dfs(start,final,start);
  if(minnum==1000)
  cout<<"-1"<<endl;
  else
  cout<<minnum<<endl;//输出边数
}