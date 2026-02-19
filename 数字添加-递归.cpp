#include<iostream>
#include<algorithm>
using namespace std;
const int N=20;
int dfs(int n,int a[N])//n表示深度
{//对于递归中同一层有不同可能，用数组存储用循环讨论
  int res=1;
  int i,j;
  for(i=1;i<=a[n-1]/2;i++)
  {
    a[n]=i;
    res+=dfs(n+1,a);
  }
  return res;
}
int main()
{
  int i,j,n,m;
  cin>>n;
  int a[N];
  a[1]=n;
  cout<<dfs(2,a)<<endl;
}
/*
  给定一个n数，再其左边添加数字，直至不能添加，添加的数字不大于前一个数字的一半
  问对数n有几种添加的方法。
*/