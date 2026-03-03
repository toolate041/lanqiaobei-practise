#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];  // 邻接表存树，避免MLE
int value[N];
int dist[N];       // 到根节点的距离（边数）
int n, k;          // n是节点数，k是步数限制

// BFS计算每个节点到根节点(1)的距离,实际上没有用到bfs,只是计算每个点到起始点的距离
void bfs() {//运用了队列进行重复操作
    memset(dist, -1, sizeof(dist));//重置数组（名字，值，sizeof(名字)）
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        
        for (int v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);//重点在这，用vector可以便捷的
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> k;
    
    // 读取节点价值
    for (int i = 1; i <= n; i++) {
        cin >> value[i];
    }
    
    // 读取n-1条边，建图（修正你的输入错误）
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    
    // 计算每个节点到根的距离
    bfs();
    
    // 计算答案：所有满足 dist[i] <= 2*k 的节点的价值和
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist[i] <= 2 * k) {  // k步最多走2k条边
            ans += value[i];
        }
    }
    
    cout << ans << endl;
    
    return 0;
}