#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
int main()
{
  int i,j,n;
  cin>>n;
  map<long long,int> cnt;//long long后面有一个,
  for(i=0;i<n;i++)//map会自动排序
  {
    long long  num;
    cin>>num;
    cnt[num]++;
  }
  for(auto&[num,times]:cnt)//&是引用，不拷贝，对cnt里循环，输出值和对应的次数
  {
    cout<<num<<" "<<times<<endl;//num和times都是cnt中可拆接对象，更直观，相当于自己命名的
  }
}