#include <iostream>
#include <algorithm>
using namespace std;
int pri[20] = {0, 0, 2, 3, 0, 5, 0, 7, 0, 0, 0, 11, 0, 13, 0, 0, 0, 17, 0, 19}; // 0以内的所有质数，不为质数则写0
// 当做全局数组
int loop[12] = {0}; // 记录每个位置的值
int main()
{
  int i, n;
  cin >> n;
  if (n % 2 == 1)
  {
    cout << "no solution" << endl;//奇数绝对不满足
    return 0;
  }
  for (i = 1; i <= n; i++)
  {
    loop[i] = i; // 从第二个也就是下表为1的地方开始赋值
  } // 第一个全排列，升序
  do
  {
    for (i = 1; i <= n; i++)
    {
      if (!pri[loop[i] + loop[i % n + 1]]) // i%n+1可以实现最后一个连接上最前面那个
      {
        break; // 这里是判断质数条件
      } 
      
    }
    if (i > n)
      {
        for (int j = 1; j < n; j++)
        {
          cout << loop[j] << " ";
        }
        cout<<loop[n]<<endl;
      }
  } while (next_permutation(loop + 2, loop + n + 1)); // 从1的位置开始，对除了1以外的n-1个数进行全排列
   //判断对了就输出这个序列，错了就生成下一个全排列验证
}