/*输入两个数，第一个数表示1-n的范围，按照数位和排序，小的在前，相同则原数小的在前，
第二个数是找第m个位置是什么数*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
using namespace std;
const int maxnum=1e6+10;
int a[maxnum],b[maxnum];
bool cmp(int x,int y)//函数是以bool为返回值的
{
  return b[x]<b[y]||(b[x]==b[y]&x<y);
}
int main()
{
  int i,j,n,m;
  cin>>n>>m;
  for(i=1;i<=n;i++)//一定要注意数组从哪里开始赋值
  {
    a[i]=i;
    int t=i;
    while(t)
    {
      b[i]+=t%10;//计算每个数的数位和放在b数组中
      t/=10;
    }
  }
  sort(a+1,a+n+1,cmp);//sort函数，对cmp重载了
  cout<<a[m]<<endl;
}