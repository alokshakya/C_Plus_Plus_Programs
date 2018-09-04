#include<iostream>
using namespace std;
#define mod 1000000007
const unsigned int M = 1000000007;
int calculate(int n,int r)
{
    int t,c=1,d=1,nCr;
    if(r>n/2)
        t=n-r;
    else
            t=r;
            int z=t;
    while(t>=1)
    {
        c=c*n; d=d*t;
        n--;t--;

    }
    nCr=c/d;
    return nCr;

}

long long C(int n, int r) {

    if(r > n / 2) r = n - r; // because C(n, r) == C(n, n - r)
    long long ans = 1;
    int i;

    for(i = 1; i <= r; i++) {
        ans = (ans*(n - r + i)%M);
        ans /= i;
       //  cout<<"ans in "<<i<<"th iter " <<ans<<endl;
    }

    return ans;
}

long long power(long long a, long long b) {
long long x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}

int main()
{
    int n,r,ans;
    cin>>n>>r; // for larger value print answer in the form of mod
    ans=calculate(n,r);
    long long y=C(n,r);
    long long z=power(n,r);
    cout<<"nCr by calculate for n="<<n<<"and r="<<r<<"is : "<< ans<<endl;
    cout<<"nCr by C for n="<<n<<"and r="<<r<<"is : "<< y<<endl;
    cout<<"nCr by power for n="<<n<<"and r="<<r<<"is : "<< y<<endl;
    return 0;
}
