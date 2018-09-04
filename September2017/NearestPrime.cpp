#include<bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if(n<2)
        return false;
    int j;
    for(j=2;j*j<=n;j++)
    {
        if(n%j==0)
            return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n;
    cin>>n;
    if(isPrime(n))
    {
        cout<<n<<"\n";
    }
    else
    {
        i=0;
        bool flag1=false,flag2=false;
        while(!flag1 && !flag2)
        {
            i++;
            flag1=isPrime(n-i);
            flag2=isPrime(n+i);
        }
        if(flag1)
        cout<<n-i<<"\n";
        if(flag2)
            cout<<n+i<<"\n";
    }
}
