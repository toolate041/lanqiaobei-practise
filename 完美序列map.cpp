#include<iostream>
#include<algorithm>
#include<iomanip>
#include<map>
using namespace std;
int main()
{
  int i,j,n,m,num;
  cin>>num;
  map<int,int>p;
  int count=0;
  for(i=0;i<num;i++)
  {
    cin>>n;
    p[n]++;
  }
  for(auto&it:p)
  {
    if(it.second<it.first)
    {
      count+=it.second;
    }
    else if(it.second>it.first)
    {
      count+=it.second-it.first;
    }
  }
  cout<<count<<endl;
}
/*小明又新学了一个概念，叫做完美序列。一个仅包含数字序列被称为完美序列，当且仅当数字序列中每个数字出现的次数等于这个数字。比如
(1)，(2,2,3,3,3)。空序列也算。
现在小明得到了一个数字序列，他想知道最少要删除多少个数字才能使得这个数字序列成为一个完美序列。

输入格式
输入包括两行。

第一行一个整数n，表示数字序列中数字的个数。

第二行，包括 n 个整数，是数字序列中具体的每个数字。

输出格式
输出一个整数，表示最少要删除的数字个数。*/