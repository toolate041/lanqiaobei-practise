/*输入一个数n,在输入n个数字，
找这n个数字组成等差数列最少需要多少项*/
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1e5 + 10;

// 手写GCD
long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() { 
    int n;
    cin >> n;
    
    long long a[maxn];  // 用long long防溢出
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    
    sort(a + 1, a + n + 1);
    
    // 求所有差值的GCD，不是最小差值！
    long long g = a[2]-a[1];
    for (int i = 3; i <= n; i++) {
        g = gcd(g, a[i] - a[i-1]);
    }
    
    if (g == 0) {
        cout << n<< endl;  // 所有数相同,就需要n项
    } else {
        cout << (a[n] - a[1]) / g + 1 << endl;
    }
    
    return 0;
}