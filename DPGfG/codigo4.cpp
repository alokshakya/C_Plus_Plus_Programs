#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    const int mod=1e9+7;
    while(t--)
    {
        ll k,l,n,i;
        cin>>k>>l>>n;
        ll birth[n+1];
        ll sum[n+1];

        birth[1]=1;
        sum[1]=1;
        for(i=1;i<=n;i++)
        {
            ll c = 0;
            if(i - l >=1)c = - birth[i - l];
            birth[i] = ((sum[i-1] + c)*k)%mod;
            sum[i] = (sum[i-1] + birth[i] + c) % mod;
            //ll die=0;
            //if((i-(l-1)))
            //ar[i]=(ar[i-1]*(k+1))%mod;
            //if((i-(l-1))>=0 && i!=(n-1))
                //ar[i]=((ar[i]-ar[i-(l-1)])+mod)%mod;
        }
        cout<<sum[n]<<"\n";
    }
    return 0;
}
