#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 1005;

int main() {
    int weight, value;  // 每个商品的体积和价值
    int num, V;         // 商品种类和背包总体积
    int dp[N];          // dp[j] 表示容量为j时的最大价值
    
    memset(dp, 0, sizeof(dp));
    cin >> num >> V;
    
    for(int i = 0; i < num; i++) {
        cin >> weight >> value;
        // 完全背包：正序遍历
        for(int j = weight; j <= V; j++) {
            dp[j] = max(dp[j], dp[j - weight] + value);
        }//不放入，或者加上前面的一起放入，一起放入的过程中也包含了前面放入的当前物品
    }
    
    cout << dp[V] << endl;
    return 0;
}//此题的物品个数是无限个