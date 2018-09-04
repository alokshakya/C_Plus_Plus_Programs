#include<bits/stdc++.h>
#define pii pair<int,int>
#define ppiiv pair<pii,int>
#define mp(x,y) make_pair(x,y)
#define f first
#define s second
using namespace std;
vector<int> adj[100001];
int n,m;

int dfs(int source,int d)
{
   stack<stack<int>> st;
   stack<int> sor;
   sor.push(source);
   st.push(sor);
   int co=0;
   while(!st.top().empty())
   {
       stack<int> t=st.top();
       st.pop();
       stack<int> st2;
       co++;
       while(!t.empty())
       {
          int tt=t.top(); t.pop();
                  vector<int>::iterator it;
               for(it=adj[tt].begin();it!=adj[tt].end();it++)
               {
                   if((*it)==d)
                   {
                       return co;
                   }
                    st2.push((*it));

               }
       }
       cout<<"st2.size()"<<st2.size()<<endl;
       if(st2.size()==0)
        break;
       st.push(st2);

   }
   return -1;
}
int dfs2(int source,int d)
{
   stack<int> st;
   vector<bool> visited(n,false);
   st.push(source);
   int co=0;
   while(!st.empty())
   {
       int t=st.top();
       st.pop();
       co++;
       if(!visited[t])
       {
           if(visited[d])
           {
               return co++;
           }
           visited[t]=true;
           vector<int>::iterator it;
           for(it=adj[t].begin();it!=adj[t].end();it++)
           {
               st.push((*it));
           }
       }


   }
   return -1;
}
void findDistance(vector<int> adj[],int source,int dest,int n)
{
    vector<bool> visited(n,false);
    vector<int> distance(n,INT_MAX);
    queue<int> q;
    q.push(source);
    distance[source]=0;
    visited[source]=true;
    while(!q.empty())
    {
        int t=q.front();
        q.pop();

            vector<int>::iterator it;
            for(it=adj[t].begin();it!=adj[t].end();it++)
            {
                if(!visited[(*it)])
                {
                    distance[(*it)]=distance[t]+1;
                    q.push(*it);
                    visited[(*it)]=true;
                }
            }
            if(visited[dest])
                break;



    }
    if(visited[dest])
            {
                cout<<distance[dest]<<endl;
            }
    else
    cout<<"-1"<<endl;
}
int main()
{
    int a,b,i,j;

    cin>>n>>m;
    //vector<int> adj[(n+1)];
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int q;
    cin>>q;
    int x,y,z;
    int t=1;
    vector<pii> query1;
    while(q--)
    {
        cin>>x;
        if(x==1)
        {
            cin>>y>>z;
            y--;z--;
            query1.push_back(mp(y,z));
                 for(int i=y;i<=z;i++)
                    {
                        for(int j=i;j<=z;j++)
                        {
                            adj[i].push_back(j);
                            adj[j].push_back(i);
                        }
                    }

        }
        if(x==2)
        {
          cin>>y;
          y--;
          int l=query1[y].f;
          int r=query1[y].s;
                    for(int i=l;i<=r;i++)
                    {
                        for(int j=i;j<=r;j++)
                        {
                            adj[i].erase(find(adj[i].begin(),adj[i].end(),j));
                            adj[j].erase(find(adj[j].begin(),adj[j].end(),i));
                        }
                    }
        }
        if(x==3)
        {
           cin>>y>>z;
           y--;z--;
           findDistance(adj,y,z,n);
           //DFS(adj,y,z);
           //cout<<res<<endl;
        }

    }

    return 0;
}
