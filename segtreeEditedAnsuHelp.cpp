#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define mp make_pair
using namespace std;
ll ar[100005];
ll tree[200020]; // first=odd, second=even

void construct_segtree(ll node, ll s, ll e)
{

    if(s==e)
    {
        if(ar[s]%2==0)
        {
           tree[node]=1;
        }
        else
        {
            tree[node]=0;
        }

    }
    else
    {
        ll mid=(s+e)/2;
        construct_segtree(2*node,s,mid);
        construct_segtree(2*node+1,mid+1,e);
       // tree[node]=mp(((tree[2*node].first)+(tree[2*node+1].first)),((tree[2*node].second)+(tree[2*node+1].second)));
       tree[node]=tree[2*node]+tree[node*2+1];
    }
    //cout<<"node number: "<<node<<", Odds: "<<tree[node].first<<", Evens: "<<tree[node].second<<endl;
}
void update(ll node, ll s,ll e, ll ind,ll val)
{
    if(s==e)
    {
        ar[ind]=val;
        if(val%2==0)
        {
           tree[node]=1;
        }
        else
        {
            tree[node]=0;
        }

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
       // tree[node]=tree[2*node]+tree[2*node+1]; pair can't be added
       // tree[node]=mp(((tree[2*node].first)+(tree[2*node+1].first)),((tree[2*node].second)+(tree[2*node+1].second)));
       tree[node]=tree[2*node]+tree[node*2+1];
    }
}
ll query(ll node, ll s, ll e, ll l, ll r)
{
    if(r<s || e<l)
    {
        //outside range of array
        return 0;
    }
    if(l<=s && e<=r)
    {
        //completely inside given range
        return tree[node];
    }
    else
    {
        //range is partially inside and partially outside
        ll mid=(s+e)/2;
        ll p1=query(2*node,s,mid,l,r);
        ll p2=query(2*node+1,mid+1,e,l,r);

        return (p1+p2);
    }
}
int main()
{
    memset(ar,0,sizeof(ar));
    memset(tree,0,sizeof(tree));
    //memset(tree,make_pair(0,0), sizeof(tree));
    ll n,i,q;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>ar[i];
    }


    construct_segtree(1,1,n);
    //cout<<"tree constructed "<<endl;
    ll ty,l,r;
    cin>>q;
    for(i=1;i<=q;i++)
    { //cout<<"query number "<<i<<endl;
        cin>>ty;
        if(ty==0)
        {
            ll ind,val;
            cin>>ind>>val;
            update(1,1,n,ind,val);
        }
        if(ty==1)
        {
            cin>>l>>r;
            ll ans=query(1,1,n,l,r);
            cout<<ans<<endl;
        }
        if(ty==2)
        {
            cin>>l>>r;
            ll ans=query(1,1,n,l,r);
            cout<<r-l+(r!=l?1:0)-ans<<endl;
            //cout<<(r-l)-ans+(l!=r?1:0)<<endl;
        }
    }

    return 0;
}
