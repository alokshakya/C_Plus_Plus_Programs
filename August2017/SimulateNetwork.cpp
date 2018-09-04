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
vector<plll> edge;
vector<ll> cost;
bool visited[N];
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

void kruskal(vector<plll> edge)
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
        cost.pb(weight);
        union1(a,b);
        //cout<<"edge "<<a<<"-->"<<b<<" with weight "<<weight<<" is added in minCost : "<<minCost<<endl;
    }
}
int main()
{
    ll nodes,edges;
    cin>>nodes>>edges;
    ll a,b,weight;
    while(edges--)
    {
        cin>>a>>b>>weight;
        edge.pb(mp(weight,mp(a,b)));//don't get confused with local edges and edge vector<plll>
    }
    ll q;
    cin>>q;
    ll val[q];
    for(ll i=0;i<q;i++)
        cin>>val[i];
    sort(val,val+q);
    sort(all(edge));
    initialize();// for making parent id of same to its value;
    kruskal(edge);
    sort(all(cost),greater<ll>());//sort in decreasing order
    ll j=0;
    ll minCost=0;
    for(ll i=0;i<cost.size();i++)
    {
         if(cost[i]>val[j])
         {
             cost[i]=val[j];
             j++;
         }
         minCost+=cost[i];
    }
    cout<<minCost<<endl;
    return 0;
}
