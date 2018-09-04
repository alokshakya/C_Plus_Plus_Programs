#include<iostream>
#include<queue>
#define ll long long
using namespace std;

int main()
{

    int n,i;
    cin>>n;
       ll ar1[n];
ll ar2[n];
ll ar3[n];
ll ans[n];
for(i=0;i<n;++i)
    {
        ar1[i]=ar2[i]=ar3[i]=0;
        ans[i]=0;
    }
    for(i=0;i<n;++i)
        cin>>ar1[i];
    for(i=0;i<n;++i)
        cin>>ar2[i];
        for(i=0;i<n;++i)
        cin>>ar3[i];


    priority_queue<ll,vector<ll>, greater<ll>> Q;
    for(i=0;i<n;++i)
        {
            Q.push(ar1[i]+ar2[i]+ar3[i]);
        }
        for(i=0;i<n;++i)
        {
            ans[i]=Q.top(); Q.pop();
        }
        int q;
        cin>>q;

    i=0;
    int a;
    while(q--)
    {
        cin>>a;
        if(i+a-1<n)
            cout<<ans[i+a-1]<<endl;
        else
            cout<<"-1"<<endl;
            i++;


    }
    return 0;

}
