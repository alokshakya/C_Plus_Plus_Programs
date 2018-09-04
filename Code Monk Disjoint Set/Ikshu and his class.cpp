#include<iostream>
#include<math.h>
#define mod 1000000007
#define MAX 100002
using namespace std;
int size[MAX];
int parent[MAX];
bool check[MAX];
long long  fact[MAX];

void cal_fact(){
	fact[0] = fact[1] = 1;
	for(long long  i=2;i<MAX;i++){
		fact[i] = i*fact[i-1];
		fact[i] %= mod;
	}
}
int find(int x)
{
	if(x != parent[x]) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}
void merge(int x, int y)
{
    int u = find(x);
		int v = find(y);

		//cout<<"find of a is "<<u<<" b is "<<v<<endl;
		if(u != v)
		parent[v] = u;
		size[u] += size[v];
}
int main()
{
    cal_fact();

    int n,m1,m2,i,a,b,ans=1;

    for(i=0;i<MAX;++i)
    {
        size[i]=1;parent[i]=i;check[i]=true;
    }
    cin>>n;
    cin>>m1;
    for(i=1;i<=m1;++i)
    {
        cin>>a>>b;
        merge(a,b);
    }


    for(i=0;i<n;i++)
    {
        int f=find(i);
       // cout<<"size of "<<i<<" is : "<<size[f]<<endl;
        if(check[f] && size[f]>1)
        {
            ans=ans*(fact[size[f]]);
            if(ans>mod)
                ans=ans%mod;
            check[f]=false;
        }
    }
    cout<<ans<<endl;
    return 0;
}
