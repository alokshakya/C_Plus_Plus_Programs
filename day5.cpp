#include<bits/stdc++.h>
using namespace std;
long long fun(long long n);//function prototype declaration
long long val[100000000];
int main()
{
int t;
cin>>t;
cout<<val[1000005];
long long f0,f1,n;
while(t--)
{
    cin>>f0>>f1>>n;
    val[0]=f0;
    val[1]=f1;
    cout<<fun(n)<<endl;

}

    return 0;
}
long long fun(long long n)
{
   long long a=0,b,c;
   if(val[n])
   {
       return val[n];
   }
   else
   {
       b=fun(n-1);
       c=fun(n-2);
       a=b+c+(b*c);
       val[n]=a;
       return a;
   }


}
