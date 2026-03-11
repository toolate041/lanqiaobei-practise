#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
  int i,j,n;
  int num[10000]={0};
  cin>>n;
  int sum=0;
  for(i=0;i<n;i++)
  {
    cin>>num[i];
    sum+=num[i];
  }
  if(sum%2==1)
  {
    cout<<"no"<<endl;
    return 0;
  }
  int target=sum/2;
  vector<bool> flag(target+1,false);
  flag[0]=true;//0的位置一定要置为true,0肯定可以到达并且循环从这里开始又值的改变
  for(i=0;i<n;i++)
  {
    for(j=target;j>=num[i];j--)
    {
      if(flag[j-num[i]])
      flag[j]=true;
    }
  }//动态规划部分，向下找，能到达的就置为true,不能的就false，经过循环就会慢慢到达target的判断
  
  if(flag[target])
  cout<<"yes"<<endl;
  else
  cout<<"no"<<endl;
}