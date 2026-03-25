#include<iostream>
#include<vector>
using namespace std;
int main()
{
  int n,i,j,k,g;
  cin>>n;
  vector<int> num(n);
  for(i=0;i<n;i++)
  {
    cin>>num[i];
  }
  for(i=1;i<n-2;i++)
  {
    for(j=0;j<i;j++)
    {
      if(num[j]<num[i])
      {
        for(k=i+1;k<n-1;k++)
        {
          if(num[k]<num[j])
          {
            for(g=k+1;g<n;g++)
            {
              if(num[g]<num[k])
              {
                cout<<"YES"<<endl;
                return 0;
              }
            }
          }
        }
      }
    }
  }
  cout<<"NO"<<endl;
  return 0;
}