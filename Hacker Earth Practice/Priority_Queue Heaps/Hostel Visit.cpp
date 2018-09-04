#include<iostream>
#include<queue>
#include<vector>
using namespace std;
#define ll long long int
int main()
{
    int q , K,ty,i;
    ll x,y,dis;
    cin>>q>>K;
    priority_queue<ll>Q;
    for(i=1; i<=q; ++i)
    {
        cin>>ty;
        if(ty==1)
        {
            cin>>x>>y;
            dis=(x-0)*(x-0) + (y-0)*(y-0);
            if(Q.size()==K)
            {
                if(dis<Q.top())
                {
                    Q.pop();
                    Q.push(dis);
                }
            }
            else
            {
                Q.push(dis);
            }
        }
        else
        {
            cout<<Q.top()<<endl;
        }
    }
    return 0;
}
