#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
using namespace std;
int monthdays[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isshunzi(char a,char b,char c)
{
  if(b==a+1&&c==b+1)
  {
    return true;
  }
  return false;
}
bool datashunzi(string s)
{
  int i,j;
  int flag=0;
  for(i=0;i<s.length()-2;i++)
  {
    bool k=isshunzi(s[i],s[i+1],s[i+2]);
    if(k)
    {
      flag=1;
      break;
    }
  }
  if(flag)
  {
    return true;
  }
  else
  {
    return false;
  }
}
int main()
{
  int year;
  int count=0;
  cin>>year;
  for(int month=1;month<=12;month++)
  {
    for(int day=1;day<=monthdays[month];day++)
    {
      string temp=to_string(year);
      if(month<10)
      {
        temp+='0';
      }
      temp+=to_string(month);//month和下面的day也必须要转化为字符串
      if(day<10)
      {
        temp+='0';
      }
      temp+=to_string(day);
      bool tt=datashunzi(temp);
      if(tt)
      count++;
    }
  }
  cout<<count<<endl;
}
/*一步步想，验证顺子，验证日期，字符串连接日期，不需要太复杂的思路*/