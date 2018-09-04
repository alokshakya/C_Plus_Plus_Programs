#include<bits/stdc++.h>
#define MAX_S 100001
#define foreach(container,it) for( __typeof((container).begin())it = (container).begin() ; it != (container).end() ; it++ )
using namespace std;
int startat[MAX_S+1]={0};
int endat[MAX_S+1]={0};
bool visited[MAX_S]={false};
int tree[MAX_S*5];
int lazy[MAX_S*5];
int ar[MAX_S]={1};
vector<int> adj[MAX_S];
int co;
void dfs(int node)
{
    if(visited[node])
        return;
    visited[node]=true;
    co++;
    startat[node]=co;
    foreach(adj[node],it)
    {
        dfs(*it);
    }
    endat[node]=co;
    //cout<<"node "<<node<<" start "<<startat[node]<<" endat "<<endat[node]<<endl;
}
void construct_segtree(int node, int s, int e)
{

    if(s==e)
    {
        tree[node]=1;
    }
    else
    {
        int mid=(s+e)/2;
        construct_segtree(2*node,s,mid);
        construct_segtree(2*node+1,mid+1,e);
       tree[node]=tree[2*node]+tree[node*2+1];
    }
}
void update(int node, int s,int e, int l,int r,int val)
{
    //cout<<"node number "<<node<<endl;
    if(s>e || s>r || e<l )
    {
       // cout<<"out of range"<<endl;
        return ;//completly out of range
    }

    if(s==e)
    {
        if(val==0)
        {
           tree[node]=0;
        }
        else
        {
            tree[node]=1;
        }
        //cout<<"node updated "<<node<<endl;

    }
    else
    {
        int mid=(s+e)/2;
        update(2*node,s,mid,l,r,val);
        update(2*node+1,mid+1,e,l,r,val);
       tree[node]=tree[2*node]+tree[node*2+1];
    }

}
int query(int node, int s, int e, int l, int r)
{
    if(r<s || e<l)
    {
        //outside range of array
        return 0;
    }
    if(l<=s && e<=r)
    {
        //completely inside given range
        return tree[node];
    }
    else
    {
        //range is partially inside and partially outside
        int mid=(s+e)/2;
        int p1=query(2*node,s,mid,l,r);
        int p2=query(2*node+1,mid+1,e,l,r);

        return (p1+p2);
    }
}
void updateRange(int node, int start, int end, int l, int r, int val)
{
    if(lazy[node])
    {
        // This node needs to be updated
        if(lazy[node]==2)
        tree[node] = 0; // Update it
        else
            tree[node]=end-start+1;
        if(start != end)
        {
            lazy[node*2] += lazy[node];                  // Mark child as lazy
            lazy[node*2+1] += lazy[node];                // Mark child as lazy
        }
        lazy[node] = 0;                                  // Reset it
    }
    if(start > end or start > r or end < l)              // Current segment is not within range [l, r]
        return;
    if(start >= l and end <= r)
    {
        // Segment is fully within range
        if(val==2)
        tree[node] = 0;
        else
            tree[node]=(end-start+1);
        if(start != end)
        {
            // Not leaf node
            if(val==2)
            {
              lazy[node*2] = 2;
              lazy[node*2+1] = 2;
            }

            else
            {
                lazy[node*2] = 1;
                lazy[node*2+1] = 1;
            }
        }
        return;
    }
    int mid = (start + end) / 2;
    updateRange(node*2, start, mid, l, r, val);        // Updating left child
    updateRange(node*2 + 1, mid + 1, end, l, r, val);   // Updating right child
    tree[node] = tree[node*2] + tree[node*2+1];        // Updating root with max value
}

int queryRange(int node, int start, int end, int l, int r)
{
    if(start > end or start > r or end < l)
        return 0;         // Out of range
    if(lazy[node])
    {
        // This node needs to be updated
        if(lazy[node]==1)
        tree[node] = (end - start + 1) ; // Update it
        else
            tree[node]=0;
        if(start != end)
        {
            lazy[node*2] += lazy[node];         // Mark child as lazy
            lazy[node*2+1] += lazy[node];    // Mark child as lazy
        }
        lazy[node] = 0;                 // Reset it
    }
    if(start >= l and end <= r)             // Current segment is totally within range [l, r]
        return tree[node];
    int mid = (start + end) / 2;
    int p1 = queryRange(node*2, start, mid, l, r);         // Query left child
    int p2 = queryRange(node*2 + 1, mid + 1, end, l, r); // Query right child
    return (p1 + p2);
}
void build1(int node,int s,int e)
{
    if(s == e)
    {
        tree[node] = 1;
        lazy[node] = 0;
        return;
    }

    int m = (s+e)/2;
    int c = 2*node;

    build1(c,s,m);
    build1(c+1,m+1,e);

    tree[node] = tree[c] + tree[c+1];
}
void update1(int node,int s,int e,int x,int y,int v)
{
    if(s > e)
        return;
    int m = (s+e)/2;
    int c = 2*node;

    if(lazy[node])
    {
        if(lazy[node] == 1)
            tree[node] = 0;
        else
            tree[node] = e - s + 1;

        if(s != e)
        {
            lazy[c] = lazy[c] = lazy[node];
        }
        lazy[node] = 0;
    }

    if(s > y || e < x)
        return;

    if(x <= s && e <= y)
    {

        if(v == 1)
            tree[node] = 0;
        else
            tree[node] = e - s + 1;

        if(s != e)
        {
            lazy[c] = lazy[c+1] = v;
        }
        return;
    }

    update1(c,s,m,x,y,v);
    update1(c+1,m+1,e,x,y,v);

    tree[node] = tree[c] + tree[c+1];
}

int query1(int node,int s,int e,int x,int y)
{
    if(s > e || s > y || e < x)
        return 0;
    int m = (s+e)/2;
    int c = 2*node;

    if(lazy[node])
    {
        if(lazy[node] == 1)
            tree[node] = 0;
        else
            tree[node] = e - s + 1;

        if(s != e)
        {
            lazy[c] = lazy[c] = lazy[node];
        }
        lazy[node] = 0;
    }

    if(x <= s && e <= y)
    {
        return tree[node];
    }

    return query1(c,s,m,x,y) + query1(c+1,m+1,e,x,y);
}
int main()
{
    int n;
    cin>>n;
    int i,root;
    for(i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        if(a==0)
            root=i;
        else
        adj[a].push_back(i);
    }
    dfs(root);
    //construct_segtree(1,1,n);
    build1(1,1,n);
    int q;
    cin>>q;
    for(i=0;i<q;i++)
    {
        int ty, s;
        cin>>ty>>s;
        if(ty==1)
        {
            //cout<<"query 1 start "<<startat[s]<<" end "<<endat[s]<<endl;
            update1(1,1,n,startat[s]+1,endat[s],2);
        }
        if(ty==2)
        {
            //cout<<"query 2 start "<<startat[s]<<" end "<<endat[s]<<endl;
            update1(1,1,n,startat[s]+1,endat[s],1);
        }
        if(ty==3)
        {
            //cout<<"query 3 start "<<startat[s]<<" end "<<endat[s]<<endl;
            int ans=query1(1,1,n,startat[s]+1,endat[s]);
            cout<<ans<<endl;
        }
    }
    return 0;
}


