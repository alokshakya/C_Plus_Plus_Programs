#include<bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
  int t,i;
  cin>>t;
  for(i=0;i<t;i++)
  {
      lli n;
      cin>>n;
      lli res=0;
      if(n%2==0)
      {
          n=(n-1)/2;
          n=n+1;
          res=2*(n*n);

      }
      else
      {
          n=(n)/2;
          n=n+1;
          res=2*(n*n);
      }
      cout<<res<<endl;
  }
}
