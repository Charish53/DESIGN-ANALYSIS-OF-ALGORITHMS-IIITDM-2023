#include <bits/stdc++.h>
#include<cmath>
//dp for denominations Ra,Rb and Rc
using namespace std;
int weight,R1,R2,R3;
int main()
{
  int a,b,k;
  cin>>weight>>R1>>R2>>R3;
  int arr[weight]={0};
  arr[R1]=arr[R2]=arr[R3]=1;
  for(int i=0;i<R1;i++)
  arr[i]=0;
  for(int i=R1+1;i<R2;i++)
  {
    if(i%R1==0)  
    arr[i]=i/R1;
  }
  for(int i=R2+1;i<R3;i++)
  {
    a=i%R2;
    b=i/R2;
    if(a==0)
    arr[i]=b;
    else if(a%R1==0)
    arr[i]=b+(i-b*R2)/R1;
    else
    {
        while(b>0)
        {
        int p=0;
        k=b-1;
        b--;
        p++;
        if((p*R2+a)%R1==0)
        {
        arr[i]=k+(p*R2+a)%R1;
        break;
        }
        }
        arr[i]=0;
    }
  }
  for(int i=R3+1;i<=weight;i++)
  {
      if(arr[i-R2]==0&&arr[i-R3]==0&&arr[i-R1]!=0)
      arr[i]=1+arr[i-R1];
      else if((arr[i-R2]==0||arr[i-R3]==0)&&arr[i-R1]!=0)
      arr[i]=1+min(arr[i-R1],max(arr[i-R2],arr[i-R3]));
      else if(arr[i-R2]!=0&&arr[i-R3]!=0&&arr[i-R1]!=0)
      arr[i]=1+min(arr[i-R1],min(arr[i-R2],arr[i-R3]));
      else if((arr[i-R1]==0)&&(arr[i-R2]==0&&arr[i-R3]==0))
      arr[i]=0;
      else if((arr[i-R1]==0)&&(arr[i-R2]!=0&&arr[i-R3]!=0))
      arr[i]=1+min(arr[i-R2],arr[i-R3]);
      else
      arr[i]=1+max(arr[i-R2],arr[i-R3]);
  }
    for(int i=0;i<=weight;i++)
    cout<<i<<"="<<arr[i]<<" ";
   return 0; 
  }


