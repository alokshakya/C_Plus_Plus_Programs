#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
ll ar[100005];
ll query3(ll node,ll s,ll e,ll start,ll step)
{
    if(s==e)
    {
        if((s-start)<0)
        {
            //(l-step)=step+(l-step);
            int xo=(s-start);
            xo+=step;
            if((xo)%(step)==0)
            {
                //cout<<"element "<<s<<" ";
                return (ar[s]*ar[s])%mod;
            }

            else
                return 0;
        }

        if((s-start)%(step)==0)
        {
            //cout<<" element "<<s<< " ";
            return (ar[s]*ar[s])%mod;
        }

        else
        {
            //cout<<" element not considered "<<s<< " ";
            return 0;
        }
    }
    ll mid=(s+e)/2;
    ll p1=query3(2*node,s,mid,start,step);
    ll p2=query3(2*node+1,mid+1,e,start,step);
    return (p1+p2)%mod;
}
int main()
{
    ll T;
    cin>>T;
    while(T--)
    {
        ll n,q;
        cin>>n>>q;
        for(ll i=1;i<=n;i++)
            cin>>ar[i];
        while(q--)
        {
            ll ty;
            cin>>ty;
            if(ty==1)
            {
                ll step;
                cin>>step;
                ll ans=query3(1,step,n,step,step);
                cout<<ans<<endl;
            }
            if(ty==2)
            {
                ll val,ind;
                cin>>ind>>val;
                ar[ind]=val;
            }

        }

    }
    return 0;
}
