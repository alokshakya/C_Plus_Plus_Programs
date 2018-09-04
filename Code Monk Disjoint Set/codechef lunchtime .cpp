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
	int z;
	cin>>z;
	while(z--)
    {
        int n,m,i,u,v;

	cin>>n>>m;
	int sia=n+1;
	int br=m+1;
	int alice[sia];
	int b[br];
	for(i = 1; i <= n+m+1; i++) {
		parent[i] = i;
		size[i] = 1;
		check[i] = true;
	}
	for(i=1;i<=n;++i)
        cin>>alice[i];
for(i=1;i<=m;++i)
    cin>>b[i];
	for(i=1;i<m;++i)
        {

		int a = find(b[i]);
		int bz = find(b[i+1]);
		if(a == bz) continue;
		parent[bz] = a;
		size[a] += size[bz];
	}
	int co=0;
	for(i=1;i<=n;++i)
        {
		int bz = find(alice[i]);
		if(size[bz]>1)
            co++;
	}
	cout<<co<<endl;
    }
	return 0;
}
