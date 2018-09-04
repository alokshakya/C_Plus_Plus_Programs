#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pll pair<ll, ll>
#define foreach(container,it) for( __typeof((container).begin())it = (container).begin() ; it != (container).end() ; it++ )
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int testcase=0;testcase<t;testcase++)
    {
        ll n,m;
        scanf("%lld %lld",&n,&m);
        ll id,t,dur;
         priority_queue<pll, vector<pll>, greater<pll> > pq;
         // pq.push(mp(2,12));
   // pq.push(mp(4,8));
    //pq.push(mp(1,2));
    //pq.push(mp(1,1));
        for(ll i=0; i<m; i++)
        {

            cin>>id>>t>>dur;
            pq.push(mp(t,dur));
        }
        vector<pll> invigilator;
        ll co=0;
                while(!pq.empty())
                {
                    ll x,y;
                    pll t=pq.top();pq.pop();
                    x=t.first;y=t.second;
                    bool found=false;
                    ll id;
                    foreach(invigilator,it)
                    {
                        if(it->second<=(x))
                        {
                           // cout<<"found "<<"x "<<x<<" AND "<<"it->second "<<it->second<<endl;
                            found=true;
                            id=it->first;
                            invigilator.erase(it);
                            break;
                        }
                    }
                    if(found)
                    {
                        invigilator.push_back(mp(id,(x+y)));
                    }
                    else
                    {
                       // cout<<"not found "<<"x "<<x<<" AND "<<"it->second "<<x+y<<endl;
                        co++;
                        invigilator.push_back(mp(co,(x+y)));
                    }
                }
                cout<<invigilator.size()<<endl;
    }
    return 0;
}
