#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define mp make_pair
#define N 100005
using namespace std;
ll ar[5*N];
ll tree[2*5*N+1]; // first=odd, second=even

void construct_segtree(ll node, ll s, ll e)
{

    if(s==e)
    {
       tree[node]=ar[s];

    }
    else
    {
        ll mid=(s+e)/2;
        construct_segtree(2*node,s,mid);
        construct_segtree(2*node+1,mid+1,e);
        //tree[node]=mp(((tree[2*node].first)+(tree[2*node+1].first)),((tree[2*node].second)+(tree[2*node+1].second)));
        tree[node]=tree[2*node]+tree[2*node+1];
    }
    //cout<<"node number: "<<node<<", Odds: "<<tree[node].first<<", Evens: "<<tree[node].second<<endl;
}
void update(ll node, ll s,ll e, ll ind,ll val)
{
    if(s==e)
    {
        ar[ind]=val;
        tree[node]=val;

    }
    else
    {
        ll mid=(s+e)/2;
        if(ind>=s && ind<=mid)
        {
            update(2*node,s,mid,ind,val);
        }
        else
        {
            update(2*node+1,mid+1,e,ind,val);
        }
        tree[node]=tree[2*node]+tree[2*node+1];

    }
}
ll query(ll node, ll s, ll e, ll l, ll r,ll val)
{
    if(r<s || e<l)
    {
        //outside range of array
        return 0;
    }
    if(s==e)
    {
        //count only leaf node
        return tree[node]/val;
    }
    else
    {
        //range is partially inside and partially outside
        ll mid=(s+e)/2;
        ll p1=query(2*node,s,mid,l,r,val);
        ll p2=query(2*node+1,mid+1,e,l,r,val);
        ll ans=p1+p2;
        return ans;
    }
}
int main()
{
    memset(ar,0,sizeof(ar));
    memset(tree,0, sizeof(tree));
    ll n,i,q;

    cin>>n>>q;
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
    }


    construct_segtree(1,1,n);
    //cout<<"tree constructed "<<endl;
    ll ty,l,r;
    for(i=1;i<=q;i++)
    { //cout<<"query number "<<i<<endl;
        cin>>ty;
        if(ty==1)
        {
            ll ind,val;
            cin>>ind>>val;
            update(1,1,n,ind,val);
        }
        if(ty==2)
        {
            cin>>r;
            ll ans=query(1,1,n,1,n,r);
            cout<<ans<<endl;
        }
    }

    return 0;
}
