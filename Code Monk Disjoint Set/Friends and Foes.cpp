#include<iostream>
using namespace std;
int size[1000005];
int parent[1000005];
bool check[1000005];
int findA(int x)
{
	if(x != parent[x]) {
		parent[x] = findA(parent[x]);
	}
	return parent[x];
}
void mergeA(int x, int y)
{
    int g=findA(x);
    int h=findA(y);
    cout<<"x is "<<g<<" y is "<<h<<endl;
    if(g!=h)
    {
            parent[h]=g; size[g]+=size[h];
    }
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
        int u = findA(a);
		int v = findA(b);
		cout<<"find of a is "<<u<<" b is "<<v<<endl;
		if(u == v) continue;
		parent[v] = u;
		size[u] += size[v];
       // mergeA(a,b);
    }
    cin>>m2;
    for(i=1;i<=m2;++i)
    {
        cin>>a>>b;
        int s=findA(a);
        int w=findA(b);
        cout<<"find of a is "<<s<<" b is "<<s<<endl;
        if(s==w)
        check[s]=false;

    }

    for(i=1;i<=n;i++)
    {
        if(check[findA(i)])
        {
            ans=max(ans,size[findA(i)]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
