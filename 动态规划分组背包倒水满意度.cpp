#include<iostream>
#include<algorithm>
using namespace std;
using ll= long long;
const int N=10005;
const int INF=-1e12;  // 负无穷表示不可达,注意数据的范围

int n,m;//n是有几个人（几个组），m是总水量（总容量）
ll f[N];//f[j]表示容量为j时的最大满意度

int main()
{
    cin>>n>>m;
    
    // 初始化：只有0容量可达，满意度为0
    for(int j=1;j<=m;j++) f[j]=INF;
    f[0]=0;
    
    int i,j,k;//用于循环的变量
    int ai,ci;//0-ai(满意度为ei)，ai-ci(满意度为bi),ci-↑(满意度为di)
    ll bi,di,ei;
    for(i=1;i<=n;i++)//有n个物品（n组）
    {
        cin>>ai>>bi>>ci>>di>>ei;
        
        // 倒序遍历容量（分组背包，每组只能选一个）
        for(j=m;j>=0;j--)
        {
            ll best=INF;//当前容量下的最优解
            
            // 选择1：给第i个人倒0毫升，满意度ei，消耗0容量
            if(f[j]!=INF) best=max(best,f[j]+ei);
            
            // 选择2：给第i个人倒ai毫升，满意度bi，消耗ai容量
            if(j>=ai && f[j-ai]!=INF) best=max(best,f[j-ai]+bi);
            
            // 选择3：给第i个人倒ci毫升，满意度di，消耗ci容量
            if(j>=ci && f[j-ci]!=INF) best=max(best,f[j-ci]+di);
            
            f[j]=best;//更新状态
        }
    }
    
    // 答案：不一定用完所有水，取0~m中的最大值
    ll ans=INF;
    for(j=0;j<=m;j++) ans=max(ans,f[j]);
    cout<<ans<<endl;
    
    return 0;
}