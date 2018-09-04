#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define mp make_pair
#define N 100005
using namespace std;
ll ar[5*N];
ll query(ll node, ll s, ll e, ll val)
{
    if(s==e)
        return ar[s]/val;
    ll mid=(s+e)/2;
    ll p1=query(2*node,s,mid,val);
    ll p2=query((2*node+1),(mid+1),e,val);
    return p1+p2;
}
int main()
{
    ll n,i,q;

    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
    }
    ll ty,l,r;
    for(i=1;i<=q;i++)
    {
        cin>>ty;
        if(ty==1)
        {
            ll ind,val;
            cin>>ind>>val;
            //update(1,1,n,ind,val);
            ar[ind]=val;
        }
        if(ty==2)
        {
            cin>>r;
            ll ans=0;
            ans=query(1,1,n,r);
            cout<<ans<<endl;
        }
    }

    return 0;
}
