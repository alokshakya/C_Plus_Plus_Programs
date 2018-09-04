#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair

using namespace std;
const int N=100005;
int parent[N];
int siz[N];
init(int n)
{
    for(int i=0;i<=n;i++)
    {
        parent[i]=i;
        siz[i]=1;
    }
}
void union1(int x,int y)
{
    parent[y]=x;
    siz[x]++;
}

int main()
{
    int n,m,i;
    cin>>n>>m;
    vector<pair<int,int>> edges;
    for(i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        if(parent[x]==parent[y])
        {
            edges.push_back(make_pair(x,y));
        }
        else
            union1(x,y);
    }
    // first check if loop exist
    int es=edges.size();
    vector<pair<int,int>>::iterator it;
    if(es>0)
    {
        if(es>1)
        {
            int mini=1000005;
            for(it=edges.begin();it!=edges.end();it++)
            {
                int l=(*it).first;
                   if(siz[l]<mini)
                   {
                       mini=siz[l];
                   }
            }
        }

    }
    else
    {
        //find minimum length connected component
    }
    return 0;
}
