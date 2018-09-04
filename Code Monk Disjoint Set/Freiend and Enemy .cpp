
#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long int
#define pb push_back
#define mk make_pair

int par[2000002];
int size[2000002];
int m[2000002],w[2000002];
int func(int x)
{
	if(x != par[x]) {
		par[x] = func(par[x]);
	}
	return par[x];
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n,rem=0;
	cin>>n;
	int q1,q2,q3,a,b,i;
	for(i = 1; i <= 2000000; i++) {
		par[i] = i; size[i]=1;
	}
	cin>>q1;
	while(q1--) {
		cin>>a>>b;
		if(b < a) {
			swap(a,b);
		}
		int u,v;
		u = func(a);
		v = func(b);
		if(par[u] == par[v]) continue;
		par[v] = par[u]; size[u]+=size[v];
	}
	cin>>q2;
	while(q2--) {
		cin>>a>>b;
		if(b < a) {
			swap(a,b);
		}
		int u,v;
		u = func(a);
		v = func(b);
		if(par[u] == par[v])
        {
           // cout<<"same group "<<a<<" , "<<b<<" and size of group :"<<size[u]<<endl;
            rem+=size[u];

        }

	}




   cout<<n-rem<<endl;
	return 0;
}
