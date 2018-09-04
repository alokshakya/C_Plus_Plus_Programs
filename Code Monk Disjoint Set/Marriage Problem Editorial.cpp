#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int par[2000002];
int m[2000002],w[2000002];
int find(int x)
{
	if(x != par[x]) {
		par[x] = find(par[x]);
	}
	return par[x];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int x,y;
	cin>>x>>y;
	int q1,q2,q3,a,b,i;
	for(i = 1; i <= 2000000; i++) {
		par[i] = i;
	}
	cin>>q1;
	while(q1--) {
		cin>>a>>b;
		if(b < a) {
			swap(a,b);
		}
		int u,v;
		u = find(a);
		v = find(b);
		if(u == v) continue;
		par[v] = par[u];
	}
	cin>>q2;
	while(q2--) {
		cin>>a>>b;
		if(b < a) {
			swap(a,b);
		}
		int u,v;
		a += 1000000;
		b += 1000000;
		u = find(a);
		v = find(b);
		if(u == v) continue;
		par[v] = par[u];
	}
	cin>>q3;
	while(q3--) {
		cin>>a>>b;
		int u,v;
		b += 1000000;
		u = find(a);
		v = find(b);
		if(u == v) continue;
		par[v] = par[u];
	}
	for(i = 1; i <= x; i++) {
		int u = find(i);
		m[u]++;
	}
	for(i = 1; i <= y; i++) {
		int u = find(i+1000000);
		w[u]++;
	}
	long long ans = 0;
	for(i = 1; i <= x; i++) {
		if(m[i]) {
			ans += (long long)(m[i])*(y-w[i]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
