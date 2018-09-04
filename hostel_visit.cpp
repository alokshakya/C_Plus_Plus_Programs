#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define ll long long
int main()
{
    int q , K,ty;
    int i,j,z;
    ll x,y,dis,op;
    cin>>q>>K;
    priority_queue<ll,vector<ll>,greater<ll>>Q;
    for(i=1; i<=K; ++i)
    {
        cin>>ty>>x>>y;
        dis=(x-0)*(x-0) + (y-0)*(y-0);
        Q.push(dis);
    }
        for(j=K+1; j<=q; ++j)
    {
        cin>>ty;
       if(ty==1)
        {
           cin>>x>>y;
           dis=(x-0)*(x-0) + (y-0)*(y-0);
           Q.push(dis);
        }
        else
        {
            ll ve[K];
            for(z=1; z<K;++z)
            {
                ve[z]=Q.top();
                Q.pop();
            }
            op=Q.top();
            cout<<op<<endl;
            //cout << op <<end;
            for(z=1; z<K;++z)
            {
                Q.push(ve[z]);
            }
       }
    }
    return 0;
}
