/*
N 架飞机准备降落到某个只有一条跑道的机场。其中第 i 架飞机在 
Ti时刻到达机场上空，到达时它的剩余油料还可以继续盘旋 
Di个单位时间，即它最早可以于 
Ti时刻开始降落，最晚可以于 
Ti+Di时刻开始降落。降落过程需要 
Li个单位时间。
一架飞机降落完毕时，另一架飞机可以立即在同一时刻开始降落，但是不能在前一架飞机完成降落前开始降落。

请你判断N 架飞机是否可以全部安全降落。

输入格式
输入包含多组数据。

第一行包含一个整数 T，代表测试数据的组数。
对于每组数据，第一行包含一个整数N。
以下 N 行，每行包含三个整数：
Ti，Di和 Li 。
输出格式
对于每组数据，输出 
YES 或者 NO，代表是否可以全部安全降落。
*/
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N=1e5+10;
int n;//代表几架飞机
bool used[N]={0};//表示安排的飞机
bool found;//是否已经安排完了
struct Plane
{
  int arrtime,waittime,downtime;//到达，等待和降落时间
  int deadtime;//降落截止日期
}plane[N];
void dfs(int k,int curtime)//已经安排了几辆飞机以及当前的时间
{
  if(found)
  return;
  if(k==n)
  {
    found=1;
    return;
  }
  int i;
  for(i=0;i<n;i++)
  {
    if(used[i])continue;
    int start=max(curtime,plane[i].arrtime);
    if(start>plane[i].deadtime)continue;//漏了这句，开始时间大于了截止时间就降落失败
    used[i]=true;
    int finishtime=start+plane[i].downtime;
    dfs(k+1,finishtime);
    used[i]=false;
  }

}
int main()
{
  int i,j,t,m;
  cin>>t;
  while(t--)
  {
    found=false;
    cin>>n;//飞机的数量
    for(i=0;i<n;i++)
    {
      cin>>plane[i].arrtime>>plane[i].waittime>>plane[i].downtime;
      plane[i].deadtime=plane[i].arrtime+plane[i].waittime;
    }
  
  memset(used,0,sizeof(used));
  sort(plane,plane+n,[](Plane a,Plane b)
  {
    return a.arrtime<b.arrtime;
  });
  dfs(0,0);
  if(found)
  cout<<"YES"<<endl;
  else
  cout<<"NO"<<endl;
}
}