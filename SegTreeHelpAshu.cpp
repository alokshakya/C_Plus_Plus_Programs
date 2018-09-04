#include<bits/stdc++.h>
#define ll long long int
#define pii pair<ll,ll>
#define mp make_pair
using namespace std;
ll ar[200005];
pii tree[400020]; // first=odd, second=even

void construct_segtree(ll node, ll s, ll e)
{

    if(s==e)
    {
        if(ar[s]%2==0)
        {
           tree[node]=mp(0,1);
        }
        else
        {
            tree[node]=mp(1,0);
        }

    }
    else
    {
        ll mid=(s+e)/2;
        construct_segtree(2*node,s,mid);
        construct_segtree(2*node+1,mid+1,e);
        tree[node]=mp(((tree[2*node].first)+(tree[2*node+1].first)),((tree[2*node].second)+(tree[2*node+1].second)));
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
           tree[node]=mp(0,1);
        }
        else
        {
            tree[node]=mp(1,0);
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
        tree[node]=mp(((tree[2*node].first)+(tree[2*node+1].first)),((tree[2*node].second)+(tree[2*node+1].second)));
    }
}
pii query(ll node, ll s, ll e, ll l, ll r)
{
    if(r<s || e<l)
    {
        //outside range of array
        return mp(0,0);
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
        pii p1=query(2*node,s,mid,l,r);
        pii p2=query(2*node+1,mid+1,e,l,r);
        ll odd=p1.first+p2.first;
        ll even= p1.second+p2.second;
        pii ans=mp(odd,even);
        return ans;
    }
}
int main()
{
    memset(ar,0,sizeof(ar));
    //memset(tree,make_pair(0,0), sizeof(tree));
    ll n,i,q;
    for(i=0;i<=400019;i++)
    {
        tree[i]=mp(0,0);
    }
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
            pii ans=query(1,1,n,l,r);
            cout<<ans.second<<endl;
        }
        if(ty==2)
        {
            cin>>l>>r;
            pii ans=query(1,1,n,l,r);
            cout<<ans.first<<endl;
        }
    }

    return 0;
}
