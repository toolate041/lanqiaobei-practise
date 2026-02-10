/*先输入有几个+/-，在输入n+m+1个数的数字，求运算最大值*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
  int i,j,n,m;
  cin>>n>>m;
  vector<long long>cnt(n+m+1);
  for(i=0;i<n+m+1;i++)
  {
    cin>>cnt[i];
  }
  sort(cnt.begin(),cnt.end());//vector使用成员函数进行排序
  long long count=0;
  if(m==0)
  {
    for(long long x:cnt)
    {
      count+=x;
    }
    cout<<count<<endl;
  }
  else{
    count=cnt[n+m]-cnt[0];
    for(i=1;i<n+m;i++)
    {
      count+=abs(cnt[i]);//最大减最小，加上其他值的绝对值
    }
    cout<<count<<endl;
  }
}
//思路：只要有一个减号，就可以用括号把所有除了最小的那个数转变为加号，本身加号的就不用改
//特殊应用于后缀表达式