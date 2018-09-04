#include<bits/stdc++.h>
using namespace std ;

typedef long long int ll ;

#define MOD 1000000007
#define M 1000000007

ll powerM(ll a, ll b)
{
    if(b == 0)
        return 1;
    if(a == 1)
        return 1;
    ll t = powerM(a,b/2) ;
    if(b % 2 == 0)
    {
        return ((t%M) * (t%M))%M ;
    }
    else
    {
        return (((((a%M) * (t%M))%M)%M) * (t%M))%M ;
    }
}

int ob_bit(ll x, ll k)
{
    return (x>>k) & 1 ;
}

int main()
{
    int n ;
    scanf("%d",&n) ;
    ll in[n] ;
    ll twos[n+2] ;
    ll t=1 ;
    twos[0]=1 ;
    for(int i=1 ; i<=n ; i++)
    {
        twos[i] = twos[i-1]*2 ;
        twos[i] %= MOD ;
    }
    vector<ll>curr ;
    curr.push_back(0) ;
    for(int i=0 ; i<n ; i++)
    {
        scanf("%lld",&in[i]) ;
    }
    if(n<1000)
    {
        for(int i=0 ; i<n ; i++)
        {
            ll tempTotal=0 ;
            ll orValue=0 ;
            for(int j=i ; j>0 ; j--)
            {
                orValue |= in[j] ;
                tempTotal += curr[j] + (orValue*twos[j-1])%MOD ;
                tempTotal %= MOD ;
            }
            orValue |= in[0] ;
            tempTotal += orValue ;
            curr.push_back(tempTotal) ;
        }
        //cout << curr[curr.size()-1] << endl ;
        //cout << twos[n-1] << endl ;
        printf("%lld\n", (((curr[curr.size()-1])%MOD) * ((powerM(twos[n-1],MOD-2))%MOD))%MOD) ;
    }
    else
    {
        ll finalSum=0 ;
        for(int i=0 ; i<31 ; i++)
        {
            int t = ob_bit(in[0], i) ;
            ll expSum = t ;
            pair<ll,ll>c ;
            c.first = 1-t ;
            c.second = t ;
            for(int j=1 ; j<n ; j++)
            {
                int st = ob_bit(in[j],i) ;
                if(st==0)
                {
                    expSum = expSum*2 ;
                    expSum %= MOD ;
                    c.first = c.first*2 + c.second ;
                    c.first %= MOD ;
                }
                else
                {
                    expSum = expSum*2 + c.first*2 + c.second ;
                    expSum %= MOD ;
                    c.second = c.first*2 + c.second*2 ;
                    c.second %= MOD ;
                    c.first = 0 ;
                }
            }
            finalSum += expSum * twos[i] ;
            finalSum %= MOD ;
        }
        //cout << curr[curr.size()-1] << endl ;
        //cout << twos[n-1] << endl ;
        //cout << finalSum << endl ;
        printf("%lld\n", (((finalSum)%MOD) * ((powerM(twos[n-1],MOD-2))%MOD))%MOD) ;
    }
    return 0 ;
}
