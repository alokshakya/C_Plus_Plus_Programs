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
int id[N];
void initialize()
{
    for(int i = 0;i < N;++i)
        id[i] = i;
}

int root(int x)
{
    while(id[x] != x)
    {
        id[x] = id[id[x]];
        x = id[x];
    }
    return x;
}

void union1(int x, int y)
{
    int p = root(x);
    int q = root(y);
    id[p] = id[q];
}

ll kruskal(vector<plll> edge)
{
    ll a,b,weight,minCost=0;
    foreach(edge,it)
    {
        a=(*it).ss.ff;//*it must be inside
        b=(*it).ss.ss;
        weight=(*it).ff;
        if(root(a)==root(b)) //both belong to same component
        {
            //cout<<"edge "<<a<<"-->"<<b<<" with weight "<<weight<<" forms cycle"<<endl;
            continue;
        }
        minCost+=weight;
        union1(a,b);
        //cout<<"edge "<<a<<"-->"<<b<<" with weight "<<weight<<" is added in minCost : "<<minCost<<endl;
    }
    return minCost;
}
int main()
{
    ll nodes,edges;
    ll t;cin>>t;
    while(t--)
    {
        vector<plll> edge;
        cin>>nodes>>edges;
        ll a,b,weight;
        while(edges--)
        {
            cin>>a>>b;
            edge.pb(mp(1,mp(a,b)));//don't get confused with local edges and edge vector<plll>
        }
        sort(all(edge));
        initialize();// for making parent id of same to its value;
        ll minCost=kruskal(edge);
        cout<<minCost<<endl;
    }

    return 0;
}
