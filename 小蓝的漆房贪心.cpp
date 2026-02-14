#include<iostream>
#include<vector>
using namespace std;

int solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    int ans = n; // 最坏情况：每天涂一个房子（k=1时）
    
    // 枚举最终变成的颜色 c（1~60）
    for (int c = 1; c <= 60; c++) {
        int days = 0;
        int i = 0;
        while (i < n) {
            if (a[i] == c) {
                // 已经是目标颜色，跳过
                i++;
            } else {
                // 需要涂色，涂区间 [i, i+k-1]
                days++;
                i += k; // 跳过这个区间
            }
        }
        ans = min(ans, days);
    }
    //对每一种颜色都进行讨论，找出了最小的天数。
    //找天数的办法：（并不是颜色多的就能成为目标颜色）
    //从头到尾进行遍历，不是所在颜色就天数++，是的话就跳过，最后用min函数得到最小值
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}