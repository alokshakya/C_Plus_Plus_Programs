#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(),(x).end()
#define foreach(v,it) for(__typeof((v).begin())it=(v).begin();it!=(v).end();it++)
#define N 100005
using namespace std;
const ll MAX_DIST=1e9+5;
vector<pll> adj[N];
bool visited[N];
ll parent[N];
ll dist[N];
ll nodes,edges;
void initialize(ll n)
{
    for(int i = 0;i <= n;++i)
        {
            dist[i] = MAX_DIST;
            parent[i]=-1;
        }
}

ll bellmanFord(ll src)
{
    initialize(nodes);
    dist[src]=0;
    parent[src]=0;
    for(ll k=1;k<nodes;k++)
    {//O(|V-1|)
        for(ll i=1;i<=nodes;i++)//O(|E|)
        {
                foreach(adj[i],it)
                {
                    ll a,b,weight;

                    b=(*it).ss;
                    weight=(*it).ff;
                    if(dist[i]==MAX_DIST) continue;
                    if( dist[i]+weight<dist[b])//checking for relaxation
                    {
                        dist[b]=dist[i]+weight;
                        parent[b]=i;
                    }
                }
        }
    }

    //step 3: check is there any negative cycle
    for(ll i=1;i<=nodes;i++)
    {
            foreach(adj[i],it)
            {
                ll a,b,weight;

                b=(*it).ss;
                weight=(*it).ff;
                if( dist[i]+weight<dist[b])//checking for relaxation
                {
                    return i;
                }
            }
    }
   return -1;
}
void printPath(int s, int d){
    if(d==-1)
    {
        cout<<"unreachable vertex ";
        return;
    }
	if(s==d)
		cout<<d<<" ";
	else
	{
		printPath(s,parent[d]);
		cout<<d<<" ";
	}
}
int main()
{
    cin>>nodes>>edges;
    ll a,b,weight;
    ll times=edges;
    while(times--)
    {
        cin>>a>>b>>weight;
        adj[a].pb(mp(weight,b));
    }
    ll start;
    cout<<"Enter start vertex "<<endl;
    cin>>start;
    ll response=bellmanFord(start);
    if(response==-1)
    {
        cout<<"No negative cycle "<<endl;
        for(ll i=2;i<=nodes;i++)
        {
            cout<<"path : ";
               printPath(start,i);
               cout<<endl;
            cout<<"distance from "<<start<<" to "<<i<<" is : "<<dist[i]<<endl;
        }

    }
    else
    {
        cout<<"Negative cycle exist print cycle "<<endl;
        printPath(response,parent[response]);
    }

    return 0;
}
/*
*Input

8 11
1 8 8
8 7 1
7 6 -1
5 6 -1
4 5 3
3 4 1
3 2 1
1 2 10
7 2 -4
2 6 2
6 3 -2

*/
