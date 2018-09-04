#include<iostream>
using namespace std;
int size[1000005];
int parent[1000005];
bool check[1000005];
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
		cout<<"find of a is "<<u<<" b is "<<v<<endl;
		if(u != v)
		parent[v] = u;
		size[u] += size[v];
}
int main()
{

    int n,m1,m2,i,a,b,ans=0;

    for(i=1;i<=1000000;++i)
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
    cin>>m2;
    for(i=1;i<=m2;++i)
    {
        cin>>a>>b;
        int s=find(a);
        int w=find(b);
        cout<<"find of a is "<<s<<" b is "<<s<<endl;
        if(s==w)
        check[s]=false;

    }

    for(i=1;i<=n;i++)
    {
        if(check[find(i)])
        {
            ans=max(ans,size[find(i)]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
