#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
const ll N=1e5+10;
int main()
{
  ll i,j,m;
  ll num,limit,order;
  cin>>num>>limit>>order;
  int n[N]={0};
  for(i=0;i<num;i++)
  {
    cin>>n[i];
  }
  ll left=0,right=0;
  int cnttotal=0;
  int cnttime=0;
  while(left!=num)
  {
    right=left;
    cnttime=0;
    while(cnttime!=order)
    {
      if(right>=num)
      break;
      if(n[right]>=limit)
      cnttime++;
      right++;
    }
    if(cnttime==order)
    {
      cnttotal+=num-right+1;
      left++;
    }
    else
    break;
  }
  cout<<cnttotal<<endl;
}
/*题目描述有 n 个数，和一个整数m。

现要从这 n 个数选出一个连续子串，要求这个字串里面至少有 
k 个数要大于等于 m。
问一共能选出多少个子串（显然子串长度要大于等于 k）。

输入描述
输入第一行是 3 个整数 n、m、k.
输入第二行是 n 个整数 

输出描述
输出一个整数表示答案。*/