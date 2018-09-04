#include<bits/stdc++.h>
#define pii pair<int,int>
#define ppiiv pair<pii,int>
#define mp(x,y) make_pair(x,y)
#define f first
#define s second
using namespace std;
int mat[10][10];
int n,m;

int dfs(pii start)
{
    vector<pii> dir(4);
    dir[0]=mp(-1,0);//N
    dir[1]=mp(0,1);//E
    dir[2]=mp(1,0);//S
    dir[3]=mp(0,-1);//W
    vector<pii>::iterator it;
    int x=start.f; int y=start.s;
    vector<ppiiv> points;
    int maxz=0;
    for(it=dir.begin();it!=dir.end();it++)
    {
        int nx=x+(*it).f; int ny=y+(*it).s;
        if(nx<0 && nx>=n) continue;
        if(ny<0 && ny>=m) continue;
        if(mat[nx][ny]==maxi) continue;
        if(mat[nx][ny]<mat[x][y])
        {
            if(mat[nx][ny]>maxz)
              maxz=mat[nx][ny];
            points.push_back(mp(mp(nx,ny),mat[nx][ny]));
        }

    }

    vector<ppiiv> eq;
    vector<ppiiv>::iterator it2;

    for(it2=points.begin();it2!=points.end();it2++)
    {
       if(((*it2).s)==maxz)
       eq.push_back(mp(mp(((*it2).f.f),((*it2).f.s)),((*it2).s)));
    }
     int eq_size=eq.size();
     if(eq_size==0)
     {
         return 0;
     }
     if(eq_size==1)
     {
         return 1+dfs(mp((eq[0].f.f),(eq[0].f.s)));
     }
     if(eq_size==2)
     {
         return 1+min((dfs(mp((eq[0].f.f),(eq[0].f.s)))),(dfs(mp((eq[1].f.f),(eq[1].f.s)))));
     }
     if(eq_size==3)
     {
         return 1+min((min((dfs(mp((eq[0].f.f),(eq[0].f.s)))),(dfs(mp((eq[1].f.f),(eq[1].f.s)))))),(dfs(mp((eq[2].f.f),(eq[2].f.s)))));
     }
     if(eq_size==4)
     {
         return 1+min((min((dfs(mp((eq[0].f.f),(eq[0].f.s)))),(dfs(mp((eq[1].f.f),(eq[1].f.s)))))),(min((dfs(mp((eq[2].f.f),(eq[2].f.s)))),(dfs(mp((eq[3].f.f),(eq[3].f.s)))))));
     }

}
int main()
{
    int a,b,i,j;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    cin>>a>>b;
    pii start;
    --a;--b; // since we are using 0 index while question uses 1 index
    start=mp(a,b);
   int result=0;
   result=dfs(start);
   cout<<result<<endl;
    return 0;
}
