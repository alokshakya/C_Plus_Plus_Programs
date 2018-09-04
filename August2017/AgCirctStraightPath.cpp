#include<bits/stdc++.h>
#define ll long long
#define pii pair< ll, ll >
#define cii pair<char,pii>
#define vi vector < int >
#define vii vector<pii>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define foreach(v,it) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )

#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define all(x) x.begin(),x.end()
#define mset(x, v) memset(x, v, sizeof(x))
#define N 1005
#define MAX 100000
using namespace std;
ll n,m;
char g[N][N];
ll dist[N][N];
ll dirx[4]={0,1,0,-1};
ll diry[4]={1,0,-1,0};
char dirN[4]={'n','e','s','w'};
bool valid(int x,int y)
{
    if((x<n && x>=0) && (y<m && y>=0))
        return (g[x][y]!='*')?true:false;
    else
        return false;
}
ll bfs(pii start, pii end)
{
    queue<cii> q;
    q.push(mp('f',start));
    dist[start.ff][start.ss]=0;
    while(!q.empty())
    {
        ll i;
        cii t=q.front();
        q.pop();
        char dname=t.ff; int x=t.ss.ff; int y=t.ss.ss;
        for(i=0;i<4;i++)
        {
            int nx=x+dirx[i]; int ny= y+diry[i]; char nd=dirN[i];
            if(valid(nx,ny))
            {
                if(dist[x][y]+1<dist[nx][ny])
                {
                    if(nd!=dname && dname!='f')
                    {
                        dist[nx][ny]=dist[x][y]+1;
                    }
                    else
                    {
                        dist[nx][ny]=dist[x][y];
                    }
                    q.push(mp(nd,mp(nx,ny)));

                }
            }
        }
    }
    if(dist[end.ff][end.ss]!=MAX)
    return dist[end.ff][end.ss];
    else
        return -1;
}
int main()
{
     scanf("%lld %lld",&n,&m);
     ll i,j;
     for(i=0;i<n;i++)
     {
         scanf("%s",&g[i]);
     }
     ll sx,sy,ex,ey;
     for(i=0;i<n;i++)
     {
         for(j=0;j<m;j++)
         {
             if(g[i][j]=='V')
             {
                 sx=i;sy=j;
             }
             if(g[i][j]=='H')
             {
                 ex=i;ey=j;
             }
             dist[i][j]=MAX;
         }
     }
     //dbg2(sx,sy);
     //dbg2(ex,ey);
         ll ans=bfs(mp(sx,sy),mp(ex,ey));
         cout<<ans<<endl;
    return 0;
}
