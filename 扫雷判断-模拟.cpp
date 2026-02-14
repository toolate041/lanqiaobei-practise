#include<iostream>
#include<algorithm>
using namespace std;
int check(int a[100][100],int n,int m)
{
  if(a[n][m]==1)
  {
    return 9;
  }
  int i,j;
  int count=0;
  for(i=-1;i<=1;i++)
  {
    for(j=-1;j<=1;j++)
    {
      if(!i&&!j)
      continue;
      if(a[n+i][m+j]==1)
      {
        count++;
      }
    }
  }
  return count;
}
int main()
{
  int i,j,n,m;
  cin>>n>>m;
  int a[100][100]={0};
  int b[100][100];
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      cin>>a[i][j];
    }
  }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      int temp=check(a,i,j);
      b[i][j]=temp;
    }
  }
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=m;j++)
    {
      cout<<b[i][j]<<" ";
    }
    cout<<endl;
  }
}