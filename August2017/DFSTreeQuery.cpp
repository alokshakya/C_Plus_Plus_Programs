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
vi adj2[N];
int n,m;
int main()
{
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        adj[x].pb(y);
        adj2[y].pb(x);
    }
    int cnt1=0,cnt2=0;
    for(int i=1;i<=n;i++)
    {
       if(adj[i].size()==0)
          cnt1++;

       if(adj2[i].size()==0)
       {
           cnt2++;
       }
    }
    cout<<max(cnt1,cnt2)<<endl;
    return 0;
}
