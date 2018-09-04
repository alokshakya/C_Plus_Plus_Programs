#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define foreach(v,it) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )

#define pii pair<int,int>
#define vi vector<int>
using namespace std;
const int MAX=100005;
int bfs(int src,vi adj[MAX],int &r,int n, bool visited[MAX]) //&r means red is passed by referance and value updated in bfs will get reflected in call
{
   //case 1: start with red
   int red1=0;int blue1=0;int i;
   int color[n+1];
   for(i=1;i<=n;i++)
    color[i]=0;
   queue<pii> Q;
   Q.push(mp(src,1));
   color[src]=1;
   visited[src]=true;
   red1++;
   while(!Q.empty())
   {
       pii t=Q.front(); Q.pop();
       int node=t.ff; int co=t.ss;
       foreach(adj[node],it)
       {
           int b=*it;
           if(co==color[b])
           {
               return -1;
           }
           if(color[b]==0)
           {
               if(co==1)
               {
                   color[b]=2;
                   Q.push(mp(b,2));
                   blue1++;
               }
               if(co==2)
               {
                   color[b]=1;
                   Q.push(mp(b,1));
                   red1++;
               }
               visited[b]=true;
           }
       }
   }
   //cout<<"starting with red then : red : "<<red1<<"  blue : "<<blue1<<endl;

   //case 2: start with blue
   int red2=0;int blue2=0;
   int color2[n+1];
   for(i=1;i<=n;i++)
    color2[i]=0;
   queue<pii> Q2;
   Q2.push(mp(src,2));
   color2[src]=2;
   blue2++;
   while(!Q2.empty())
   {
       pii t=Q2.front(); Q2.pop();
       int node=t.ff; int co=t.ss;
       foreach(adj[node],it)
       {
           int b=*it;
           if(co==color2[b])
           {
               return -1;
           }
           if(color2[b]==0)
           {
               if(co==1)
               {
                   color2[b]=2;
                   Q2.push(mp(b,2));
                   blue2++;
               }
               if(co==2)
               {
                   color2[b]=1;
                   Q2.push(mp(b,1));
                   red2++;
               }
           }
       }
   }
   //cout<<"starting with blue then : red : "<<red2<<"  blue : "<<blue2<<endl;
   r=max(red1,red2);
   return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vi adj[n+1];
        int i,a,b;
        for(i=1;i<=m;i++)
        {
            cin>>a>>b;
            adj[a].pb(b);
            adj[b].pb(a);
        }
        int ans=0;
        bool visited[n+1];
        bool fl=false;
        for(i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                int red=0;
                int res=bfs(i,adj,red,n,visited);
                if(res==-1)
                {
                    cout<<"No"<<endl;
                    fl=true;
                    break;
                }
                else
                    ans+=red;
            }
        }
        if(!fl)
        cout<<ans<<endl;
    }
    return 0;
}
