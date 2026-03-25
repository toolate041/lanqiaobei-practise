#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5+10;
vector<int> g[N];
int dp[N][2];  // dp[u][0]:不选u, dp[u][1]:选u
int n;

void dfs(int u, int fa) {
    dp[u][1] = 1;  // 选u，包括u自己
    dp[u][0] = 0;  // 不选u
    
    for (int v : g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        // 转移
        dp[u][1] += dp[v][0];           // 选u，则子节点不能选
        dp[u][0] += max(dp[v][0], dp[v][1]); // 不选u，子节点可选可不选
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    
    dfs(1, 0);
    
    // 答案 = max(不选根, 选根)
    cout << max(dp[1][0], dp[1][1]) << endl;
    
    return 0;
}