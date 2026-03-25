#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 205;  // V最大200

int main() {
    int weight, value, s;
    int num, V;
    int dp[N];
    
    memset(dp, 0, sizeof(dp));
    cin >> num >> V;
    
    for(int i = 0; i < num; i++) {
        cin >> weight >> value >> s;
        
        // 朴素解法：正确版本
        for(int j = V; j >= weight; j--) {  // 01背包的逆序
            for(int k = 1; k <= s && k * weight <= j; k++) {  // 尝试放1~s个
                dp[j] = max(dp[j], dp[j - k * weight] + k * value);
            }//把对商品数量的讨论放在内部，就不会出现情况重复。
        }
    }
    
    cout << dp[V] << endl;
    return 0;
}//多重背包问题相比于完全背包问题多一个对商品数量的讨论