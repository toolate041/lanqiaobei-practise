#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
const int N=1e5+10;
queue<int> q;
vector<int> p[N];
int dist[N];
void  bfs(int num)//传入了一个最开始的起点
{
  q.push(num);
  dist[num]=0;
  while(!q.empty())
  {
    int flag=q.front();
    q.pop();
    for(int i:p[flag])
    {
      if(dist[i]==-1)
      {
        dist[i]=dist[flag]+1;
        q.push(i);
      }
    }
  }
}
int main()
{
  memset(dist,-1,sizeof(dist));
  int i,j,n,m,cnt,order,k;
  cin>>cnt;
  for(i=0;i<cnt-1;i++)
  {
    cin>>n>>m;
    if(i==0)
    k=n;
    p[n].push_back(m);
    p[m].push_back(n);
  }
  bfs(k);
  cin>>order;
  for(i=0;i<order;i++)
  {
    cin>>n>>m;
    if(dist[n]<dist[m])
    {
      cout<<"Ancestor"<<endl;
    }
    else if(dist[n]==dist[m])
    {
      cout<<"Sibling"<<endl;
    }
    else if(dist[n]>dist[m])
    {
      cout<<"Descendant"<<endl;
    }
  }
}