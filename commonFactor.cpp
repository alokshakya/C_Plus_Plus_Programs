#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    ll a,b;
    cin>>a>>b;
    ll c=min(a,b);
    ll co=0;
    set<ll> s;
    for(ll i=1;i*i<=a;i++)
    {
        if(a%i==0)
        {
            s.insert(i);
            s.insert((a/i));
        }

    }
    set<ll>::iterator it;
    for(it=s.begin(); it!=s.end();it++)
    {
        if(b%(*it)==0)
        {
            co++;
        }
    }

    cout<<co<<endl;


    return 0;
}
