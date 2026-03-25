#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 2005;
struct goods
{
  int price;
  int time;
} list[2005];
int main()
{
  int i, j, n, m;
  cin >> n; // n件商品
  for (i = 0; i < n; i++)
  {
    cin >> list[i].time >> list[i].price;
  }
  sort(list, list + n, [](const goods &a, const goods &b)
       { return a.price < b.price; });
  ll dp[N];   // 表示j个商品的总时间
  ll cost[N]; // 表示j个商品的最小价值

  for (i = 0; i <= n; i++)
  {
    dp[i] = -1;
    cost[i] = 1e18;
  }
  dp[0] = 0;
  cost[0] = 0;
  int k = 0;
  for (i = 1; i <= n; i++) // 表示有n个物品
  {
    for (j = i; j >= 1; j--) // 倒序
    {
      if (dp[j - 1] >= 0)
      {
        ll newtime = dp[j - 1] + list[i - 1].time;
        ll newcost = cost[j - 1] + list[i - 1].price;
        if (newtime > dp[j] || (newtime == dp[j] && newcost < cost[j]))
        {
          dp[j] = newtime;
          cost[j] = newcost;
        }
      }
    }
  }
  ll ans = 1e18;
  for (j = 0; j <= n; j++)
  {
    if (dp[j] >= n - j)
    {
      ans = min(ans, cost[j]);
    }
  }
  cout << ans << endl;
}