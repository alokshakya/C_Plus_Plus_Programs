#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int parent[1000002];
int size[1000002];
bool check[1000002];
int find(int x)
{
	if(x != parent[x]) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,m1,m2,i,u,v;
	cin>>n;
	for(i = 1; i <= n; i++) {
		parent[i] = i;
		size[i] = 1;
		check[i] = true;
	}
	cin>>m1;
	while(m1--) {
		cin>>u>>v;
		int a = find(u);
		int b = find(v);
		if(a == b) continue;
		parent[b] = a;
		size[a] += size[b];
	}
	cin>>m2;
	while(m2--) {
		cin>>u>>v;
		int a = find(u);
		int b = find(v);
		if(a == b) {
			check[a] = false;
		}
	}
	int ans = 0;
	for(i = 1; i <= n; i++) {
		if(check[find(i)]) {
			ans = max(ans,size[find(i)]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
