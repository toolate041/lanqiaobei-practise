#include<iostream>
#include<set>
using namespace std;
int main()
{
  int i,j,n,m;
  string time;
  int num;
  cin>>num;
  set<int> p;
  while(num--)
  {
    cin>>time>>n;
    p.insert(n);
  }
  for(auto it=p.begin();it!=p.end();it++)
  {
    cout<<*it<<endl;
  }
  //set本身实现了自动排序，auto实现自动类型推导，
  //使得可以利用for循环输出set集合的内容。
}