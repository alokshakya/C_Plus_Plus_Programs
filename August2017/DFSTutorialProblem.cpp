#include<bits/stdc++.h>
#define pii pair< int, int >
#define vi vector < int >
#define vii vector<pii>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define foreach(v,it) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define all(x) x.begin(),x.end()
#define mset(x, v) memset(x, v, sizeof(x))
#define N 100005
using namespace std;
vi adj[N];//for graph
int n,m,cnt=0;
bool visited[N];
void dfs(int src)
{
   visited[src]=true;
   cnt++;
   foreach(adj[src],it)
   {
       if(!visited[*it])
        dfs(*it);
   }
}
int main()
{
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    int head;
    cin>>head;
    dfs(head);
    cout<<n-cnt<<endl;
    return 0;
}
