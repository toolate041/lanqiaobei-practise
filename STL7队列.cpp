#include<iostream>
#include<queue>
using namespace std;

int main()
{
    int n, m;
    queue<int> p;
    cin >> n >> m;
    
    int num[101] = {0};
    int forw = 1;
    int count = 0;
    
    // 先把所有人标记为未出圈（num[i]=0）
    // 需要出队n个人
    
    while(count < n)
    {
        // 数3个未出圈的人，第3个出圈
        int flag = 0;
        while(flag < m)
        {
            if(num[forw] == 0)  // 未出圈才报数
            {
                flag++;
                if(flag == m)     
                {
                    p.push(forw);
                    num[forw] = 1;
                    count++;
                }
            }
            // 移动到下一个位置
            forw++;
            if(forw > n) forw = 1;
        }
    }
    
    while(!p.empty())
    {
        cout << p.front() << " ";
        p.pop();
    }
    cout << endl;
    
    return 0;
}