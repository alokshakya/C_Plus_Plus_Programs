#include<bits/stdc++.h>
using namespace std;
list<int> *adj;

void dfs(int vis[],int a[],int i,vector< pair<int,int> > &v)
{
    vis[i]=1;
    v.push_back(make_pair(a[i],i));
    list<int>::iterator j;
    for(j=adj[i].begin();j!=adj[i].end();j++)
    {
        if(vis[*j]==0)
        {
            dfs(vis,a,*j,v);
        }
    }
}


int main()
{
        int n,m;
        cin>>n>>m;
        int a[n],numb=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            numb+=a[i];
        }
        int x,y;
        adj=new list<int> [n];
        while(m--)
        {
            cin>>x>>y;
            x-=1;y-=1;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int vis[n],kill=0;
        memset(vis,0,sizeof(vis));
        vector<int> index;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                vector< pair<int,int> > v;
                dfs(vis,a,i,v);
                sort(v.begin(),v.end());
                int ans=v[v.size()-1].first;
                int ind=v[v.size()-1].second;
                kill+=ans;
                int flag=0;
                for(int j=v.size()-1;j>=0&&flag==0;j--)
                {
                    if(v[j].first==ans)
                    {
                        if(v[j].second<ind)
                        {
                            ind=v[j].second;
                        }
                    }
                    else
                    flag=1;
                }
                index.push_back(ind);
            }

        }
        cout<<kill<<" "<<(numb-kill)<<endl;

        sort(index.begin(),index.end());

        for(int i=0;i<index.size();i++)
        cout<<index[i]+1<<" ";
        cout<<endl;
}
