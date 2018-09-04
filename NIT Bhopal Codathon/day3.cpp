#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef int iii;
#define int long long
#define mp make_pair
#define pb push_back
#define ff first
#define ss second
#define debug( x) cout << " " << #x << " = " << x << " "
#define ol cout << endl
#define os cout << " "

int n;
vector< pair< pair< int, int>, int> > E;
bool inDijTree[100005];
vector< int> adj[ 100005];

bool visited[100005];
int cst[100005];

set< pair< int, pair< int, int> > > s;


void dijkstra( int st)
{
	s. insert( mp( 0, mp( st, -1) ) );

	while( s. size() )
	{
		int u = s. begin() -> ss. ff, w = s. begin() -> ff, e = s. begin() -> ss. ss;
		s. erase( s. begin() );
		if( visited[u] ) continue;
		visited[u] = true;
		cst[u] = w;
		if( e != -1) inDijTree[e] = true;

		for( int i = 0; i < adj[u]. size(); i++)
		{
			int en = adj[u][i];
			int v = E[en].ff.ff + E[en].ff.ss - u;
			int wt = E[en].ss;

			if( visited[v] ) continue;
			s. insert( mp( w + wt, mp( v, en) ) );
		}
	}

	return;
}


void solve()
{
	int e;
	scanf( "%lld %lld", &n, &e);
	for( int i = 0; i < e; i++)
	{
		int u, v, w;
		scanf( "%lld %lld %lld", &u, &v, &w);

		E.pb( mp( mp( u, v), w) );
		adj[u]. pb( i);
		adj[v]. pb( i);
	}

	dijkstra( 1);

	for( int i = 0; i < E.size(); i++)
	{
		if( inDijTree[i] ) continue;
		int u = E[i].ff.ff, v = E[i].ff.ss;
		int diff = cst[u] - cst[v];
		if( diff < 0) diff *= -1;
		E[i].ss = diff;
	}

	int ans = 0;
	for( int i = 0; i < E.size(); i++) ans += E[i].ss;
	printf( "%lld", ans);

	return;
}

iii main()
{
	solve();
	return 0;
}
