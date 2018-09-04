#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int parent[2000005];
int size[2000005];
int alice[2000005];
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
	for(int test=1;test<=z;test++)
    {

        int n,m,i,u,v;

	cin>>n>>m

	for(i = 1; i<=(n+m+1); i++)
        {
		parent[i] = i;
		size[i] = 1;
		check[i] = true;
	}

	for(i=1;i<=n;++i)
        cin>>alice[i];
	cin>>u;
	for(i=1;i<m;++i)
        {
		cin>>v;
		int a = find(u);
		int b = find(v);
		if(a == b) continue;
		parent[b] = a;
		size[a] += size[b];
		u=v;
	}
	int co=0;
	for(i=1;i<=n;++i)
        {

		int b = find(alice[i]);
		if(size[b]>1)
            co++;
	}
	cout<<co<<endl;
    }
	return 0;
}
