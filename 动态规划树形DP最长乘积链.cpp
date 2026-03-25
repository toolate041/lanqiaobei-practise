#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int N=1e5+10;
vector<int> p[N];//用于记录边的连接
void dfs(int root)
{

}
int main()
{
  int i,j,k;
  int n,val,down,up;
  cin>>n;
  for(i=1;i<n;i++)
  {
    cin>>up>>down>>val;
    p[up].push_back(down);
    p[down].push_back(up);
  }
  
}
