#include<bits/stdc++.h>
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define N 100005
using namespace std;

vi adj[N];
int tin[N],tout[N];
int timer;

void dfs(int cur,int par)
{
    int i;
    tin[cur] = ++timer;
    for(i=0;i<adj[cur].size();i++)
    {
        int nxt = adj[cur][i];
        if(nxt != par)
        {
            dfs(nxt,cur);
        }
    }
    tout[cur] = timer;
   // dbg2((tin[cur]),(tout[cur]));
  // cout<<"node "<<cur<<" start "<<tin[cur]<<" out "<<tout[cur]<<endl;
}

struct node
{
    int cnt;
    int lazy;
}t[4*N];

void build(int node,int s,int e)
{
    if(s == e)
    {
        t[node].cnt = 1;
        t[node].lazy = 0;
        return;
    }

    int m = (s+e)/2;
    int c = 2*node;

    build(c,s,m);
    build(c+1,m+1,e);

    t[node].cnt = t[c].cnt + t[c+1].cnt;
}

void update(int node,int s,int e,int x,int y,int v)
{
    if(s > e)
        return;
    int m = (s+e)/2;
    int c = 2*node;

    if(t[node].lazy)
    {
        if(t[node].lazy == 1)
            t[node].cnt = 0;
        else
            t[node].cnt = e - s + 1;

        if(s != e)
        {
            t[c].lazy = t[c+1].lazy = t[node].lazy;
        }
        t[node].lazy = 0;
    }

    if(s > y || e < x)
        return;

    if(x <= s && e <= y)
    {

        if(v == 1)
            t[node].cnt = 0;
        else
            t[node].cnt = e - s + 1;

        if(s != e)
        {
            t[c].lazy = t[c+1].lazy = v;
        }
        return;
    }

    update(c,s,m,x,y,v);
    update(c+1,m+1,e,x,y,v);

    t[node].cnt = t[c].cnt + t[c+1].cnt;
}

int query(int node,int s,int e,int x,int y)
{
    if(s > e || s > y || e < x)
        return 0;
    int m = (s+e)/2;
    int c = 2*node;

    if(t[node].lazy)
    {
        if(t[node].lazy == 1)
            t[node].cnt = 0;
        else
            t[node].cnt = e - s + 1;

        if(s != e)
        {
            t[c].lazy = t[c+1].lazy = t[node].lazy;
        }
        t[node].lazy = 0;
    }

    if(x <= s && e <= y)
    {
        return t[node].cnt;
    }

    return query(c,s,m,x,y) + query(c+1,m+1,e,x,y);
}

int main()
{
    int n,i;
    cin>>n;

    assert(1 <= n && n <= 100000);

    int root = -1;
    for(i=1;i<=n;i++)
    {
        int j;
        cin>>j;

        assert(0 <= j && j <= n);

        if(j == 0)
            root = i;
        else
            adj[j].pb(i);
    }

    dfs(root,0);

	build(1,1,n);

    int q;
    cin>>q;

    assert(1 <= q && q <= 100000);

    while(q--)
    {
        int op,u;
        cin>>op>>u;

        assert(1 <= op && op <= 3);
        assert(1 <= u && u <= n);

        if(op <= 2)
        {
            //cout<<"node "<<u<<" : start : "<<tin[u]+1<<" : out : "<<tout[u]+1<<endl;
            update(1,1,n,tin[u]+1,tout[u],3-op);
        }
        else
        {
            //cout<<"node "<<u<<" : start : "<<tin[u]+1<<" : out : "<<tout[u]+1<<endl;
            int ans = query(1,1,n,tin[u]+1,tout[u]);
            cout<<ans<<endl;
        }
    }
    return 0;
}
