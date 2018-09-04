#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int parent[200005];
int size[200005];
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
	int n,i,u,v,t;
	cin>>n;
	t=n;
	for(i = 1; i <= 2*n+1; i++) {
		parent[i] = i;
		size[i] = 1;
	}
	while(t--) {
		cin>>u>>v;
		int a = find(u);
		int b = find(v);
		if(a == b) continue;
		parent[b] = a;
		size[a] += size[b];
	}

	int mini = 2000,maxa=2;
	for(i=1;i<=(2*n+1);++i)
    {
        int a=find(i);
        if(size[a]>=maxa)
            maxa=size[a];
        if(size[a]<mini && size[a]>1)
            mini=size[a];
    }

	cout<<mini<<" "<<maxa<<endl;
	return 0;
}
