#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MAXN 2007
using namespace std;

int n;
int g[MAXN][MAXN], rev_g[MAXN][MAXN];
int h[MAXN][MAXN], rev_h[MAXN][MAXN];;
int dist[MAXN];
int done[MAXN];

int tmp_dist[MAXN];

void djk(int src, int arr[][MAXN]) {
	/*
	if(src == 0)
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	for(int i=0;i<n;i++) dist[i] = INF, done[i] = false;
	dist[src] = 0;
	while(1) {
		int u = -1, best_dist = INF;
		for(int i=0;i<n;i++) {
			if(!done[i] && dist[i] < best_dist) {
				u = i;
				best_dist = dist[i];
			}
		}
		if(best_dist >= INF) break;

		for(int v=0;v<n;v++) {
			if(!done[v] && arr[u][v] != INF && u != v) {
				if(dist[v] > dist[u] + arr[u][v]) {
					dist[v] = dist[u] + arr[u][v];
				}
			}
		}
		done[u] = true;
	}
}

int main() {
	cin >> n;
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin >> g[i][j];
			if(i == j) g[i][j] == INF;
			rev_g[j][i] = g[i][j];
		}
	}
	for(int i=0;i<n;i++) {
		for(int j=0;j<n;j++) {
			cin >> h[i][j];
			if(i == j) h[i][j] == INF;
			rev_h[j][i] = h[i][j];
		}
	}
	int u, v; cin >> u >> v;
	u--, v--;

	// A-C road + C-B rail => djk(A, g) + djk(B, rev_h)
	int ans = INF;
	djk(u, g);
	for(int i=0;i<n;i++) {
		tmp_dist[i] = dist[i];
		//cout << tmp_dist[i] << " ";
	}
	//cout << "\n";

	for(int i=0;i<n;i++) dist[i] = INT_MAX, done[i] = false;
	djk(v, rev_h);

	/*
	for(int i=0;i<n;i++) {
		cout << dist[i] << " ";
	}
	cout << "\n";
	*/

	for(int i=0;i<n;i++) {
		if(i != u && i != v) {
			ans = min(ans, tmp_dist[i] + dist[i]);
		}
	}

	// A-C rail + C-B road => djk(A, h) + djk(B, rev_g)
	djk(u, h);
	for(int i=0;i<n;i++) {
		tmp_dist[i] = dist[i];
		//cout << tmp_dist[i] << " ";
	}
	//cout<<"\n";
	djk(v, rev_g);
	for(int i=0;i<n;i++) {
		if(i != u && i != v) {
			ans = min(ans, tmp_dist[i] + dist[i]);
		}
	}

	cout << ans << "\n";
}
