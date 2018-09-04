#include<bits/stdc++.h>
#define ll long long
using namespace std;
int gcd(ll a,ll b)
{
    if(a==0) return b;
    return gcd(b%a,a);
}
int power(ll x,ll y,ll m)
{
    if(y==0) return 1;
    ll p=power(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}
ll modInverse(ll a,ll m)
{
    ll g=gcd(a,m);
    if(g!=1)
    {
        cout<<"Inverse does not exist "<<endl;
        return -1;
    }
    else
        return power(a,m-2,m);
}
void fastscan(int &number)
{
    //variable to indicate sign of input number
    bool negative = false;
    register int c;

    number = 0;

    // extract current character from buffer
    c = getchar();
    if (c=='-')
    {
        // number is negative
        negative = true;

        // extract the next character from the buffer
        c = getchar();
    }

    // Keep on extracting characters if they are integers
    // i.e ASCII Value lies from '0'(48) to '9' (57)
    for (; (c>47 && c<58); c=getchar())
        number = number *10 + c - 48;

    // if scanned input has a negative sign, negate the
    // value of the input number
    if (negative)
        number *= -1;
}
int main()
{
    int n,i;
    fastscan(n);
    ll ar[n];
    for(i=0;i<n;++i)
    {
        int a;
        fastscan(a);
        ar[i]=a;
    }

    ll prod=1;
    ll sum[n];
    int m=1e9+7;
    for(i=0;i<n;i++)
    {
        prod=(prod*(ar[i]+1))%m; // (a*b)%M=((a%M)*(b%M))%M
        //cout<<"Prod : "<<prod<<"\n";
        sum[i]=((ar[i]*(ar[i]+1))/2)%m;
        //cout<<"Sum : "<<sum[i]<<"\n";
    }
    ll pow[n];
    ll result=1;
    for(i=0;i<n;i++)
    {
        ll a=ar[i]+1;
        ll inv=modInverse(a,m);

        //cout<<"Inverse of "<<a<<" is : "<<inv<<endl;
        pow[i]=((sum[i]*prod)%m*(inv))%m;
        //cout<<pow[i]<<" ";
        result=(result*(pow[i]+1))%m;
    }
    cout<<result<<endl;



    return 0;
}
