#include<iostream>
using namespace std;
int size[100005];
int parent[100005];
bool check[100000];
int findA(int x)
{
	if(x != parent[x]) {
		parent[x] = findA(parent[x]);
	}
	return parent[x];
}
void merge(int x, int y)
{
    int u = findA(x);
		int v = findA(y);
		//cout<<"find of a is "<<u<<" b is "<<v<<endl;
		if(u != v)
		parent[v] = u;
		size[u] += size[v];
}
int main()
{

    int n,m1,m2,i,a,b,ans=0;

    for(i=1;i<=100000;++i)
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


    int Min=size[findA(1)];
   int Max=size[findA(1)];
    for(i=1;i<=n;i++)
    {
       if(size[findA(i)]>Max)
       {
           Max=size[findA(i)];
       }
       if(size[findA(i)]<Min)
       {
           Min=size[findA(i)];
       }
    }
    cout<<Max-Min<<endl;
    return 0;
}
