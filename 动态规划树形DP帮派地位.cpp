#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
using ll=long long;
const int N=1e5+10;
bool has_parent[N]={0};
vector<int> p[N];
int dp[N]={0};//dp[i]表示i有几个手下

void dfs(int root)
{
  int j,k;
  dp[root]=0;
  for(int i:p[root])
  {
    dfs(i);
    dp[root]++;
    dp[root]+=dp[i];

  }
}

int main()
{
  int n,order;//n是几个人，order是编号
  int i,j,k;
  int down,up;
  cin>>n>>order;
  for(i=0;i<n-1;i++)
  {
    cin>>down>>up;
    p[up].push_back(down);
    has_parent[down]=true;
  }
  int root;
  for(i=1;i<=n;i++)
  {
    if(has_parent[i]==false)
    {
      root=i;
      break;
    }
  }
  dfs(root);
   vector<pair<int, int>> people;  // (手下人数, 编号)
    for (int i = 1; i <= n; i++) {
        people.push_back({dp[i], i});
    }
    
    // 排序：手下人数降序，人数相同编号升序
    sort(people.begin(), people.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
        if (a.first != b.first) return a.first > b.first;
        return a.second < b.second;
    });
    
    // 找 m 的排名
    for (int i = 0; i < n; i++) {
        if (people[i].second == order) {
            cout << i + 1 << "\n";  // 排名从1开始
            break;
        }
    }
    

}