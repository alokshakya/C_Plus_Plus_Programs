#include <bits/stdc++.h>
#define pii pair<int,int>
#define piii pair<int,pii>
using namespace std;
bool isPrime(int n)
{
    if(n<2)
    return false;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}
int main()
{
    int s=98562124;
    int mi=INT_MAX;
    int di=0;
    int index=0;
    for(int i=2;i<=s;i++)
    {
        if((s-i)<0) break;
        if(isPrime(i) && isPrime(s-i))
        {
            int di=(s-i)-i;
            if(di>=0 && mi>di)
            {
                mi=di;
                index=i;
            }
        }
    }
    int a=index;int b=(s-index);
    cout<<a<<" "<<b<<"\n";
    return 0;
}

