#include<iostream>
#include<algorithm>
using namespace std;
using ll=long long;
const int N=1e5+10;  // B最大1e5，所以数组开到1e5+10足够

struct Course {
    int wait, end;
    ll price;
} courses[55];  // N<=50

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n,i;
    cin >> n;
    
    int maxEnd = 0;
    for(int i = 0; i < n; i++) {
        cin >> courses[i].wait >> courses[i].end >> courses[i].price;
        maxEnd = max(maxEnd, courses[i].end);
    }
    
    // 按结束时间排序（关键！必须按结束时间从小到大处理）
    sort(courses, courses + n, [](const Course& a, const Course& b) {
        return a.end < b.end;
    });//关键在于要对结束时间进行排序
    
    // dp[t] 表示在时间t之前（含t）能获得的最大收益
    // 注意：maxEnd最大1e5，数组N=1e5+10够用
    ll dp[N] = {0};  // 初始化为0
    
    int idx = 0;  // 当前处理到第几个课程
    for(int t = 1; t <= maxEnd; t++) {
        dp[t] = dp[t-1];  // 继承上一时刻的最大收益（不选任何课程）
        
        // 处理所有结束时间为t的课程
        while(idx < n && courses[idx].end <= t) {
            int w = courses[idx].wait;
            ll p = courses[idx].price;
            // 如果能在t时刻完成这个课程（即t>=w），则尝试更新
            if(t >= w) {
                dp[t] = max(dp[t], dp[t - w] + p);
            }
            idx++;
        }
    }
    
    // 输出maxEnd时刻的最大收益
    ll maxprice=0;
    for(i=0;i<=maxEnd;i++)
    {
      maxprice=max(maxprice,dp[i]);
    }
    cout<<maxprice<<endl;
    
    return 0;
}