#include<iostream>
#include<algorithm>
using namespace std;
int ans=0;
int mul=1;
void dfs(int dep)
{
  int i;
  if(mul>384||mul==0)
  return;
  if(dep==5)
  {
    if(mul==384)///到了dep=5之后才结束，不是4
    ans++;
    return;
  }
  for(i=1;i<=9;i++)
  {
    if(dep==1&&i==0)
    continue;
    mul*=i;
    dfs(dep+1);
    mul/=i;//避开0,0会干扰运算
  }
}
int main()
{
  dfs(1);
  cout<<ans<<endl;
}