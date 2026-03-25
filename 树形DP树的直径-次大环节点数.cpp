#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int N=1e5+10;
vector<int> p[N];
pair<int,int> bfs(int u)
{
  vector<int> dist(N,-1);//起始点距离dist[i]中i的距离
  //初始化dist数组时应该是用小括号，空间＋赋值
  queue<int> q;
  dist[u]=0;
  q.push(u);
  int far =u;//记录最远的路径
  while(!q.empty())
  {
    int k=q.front();
    q.pop();
    far=k;//最后出队的是最远距离
    for(int i:p[k])
   {
    if(dist[i]==-1)
    {
    dist[i]=dist[k]+1;
    q.push(i);
    }

    //bfs不是递归算法，用队列和循环即可解决
   }

  }
  return {far,dist[far]};
}
int main()
{
  int i,j,n,k;
  int up,down;
  cin>>n;
  for(i=0;i<n-1;i++)
  {
    cin>>up>>down;
    p[up].push_back(down);
    p[down].push_back(up);
  }
  auto[p1,_]=bfs(1);
  auto[p2,D]=bfs(p1);//D是最远距离
  //两个auto的含义是从一个点找端点，再从一个端点找另一个端点
  cout<<D<<endl;
}