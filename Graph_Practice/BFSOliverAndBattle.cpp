#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define f first
#define s second
#define foreach(container,it) for( __typeof((container).begin())it = (container).begin() ; it != (container).end() ; it++ )
using namespace std;
int mat[1005][1005];
int m,n;
int makeGroup(pii g)
{
    vector<pii> dir(8);
            dir[0]=mp(-1,0);//N
            dir[1]=mp(0,1);//E
            dir[2]=mp(1,0);//S
            dir[3]=mp(0,-1);//W
            dir[4]=mp(-1,1);//NE
            dir[5]=mp(1,1);//SE
            dir[6]=mp(1,-1);//SW
            dir[7]=mp(-1,-1);//NW
            pii start=g;
            queue<pii> q;
            q.push(start);
            mat[g.f][g.s]=-1;
            int co=0;
            while(!q.empty())
            {
                pii t=q.front();
                q.pop();
                co++;
                int x=t.f; int y=t.s;
                foreach(dir,it)
                {
                    int nx=x+(*it).f;int ny=y+(*it).s;
                    if(nx<0 && nx>=n) continue;
                    if(ny<0 && ny>=m) continue;
                    if(mat[nx][ny]==0) continue;
                    if(mat[nx][ny]==-1) continue;
                    if(mat[nx][ny]==1)
                    {
                        mat[nx][ny]=-1;
                        q.push(mp(nx,ny));
                    }
                }

            }
            return co;

}
void solve()
{

            int i,j;
            vector<int> sizeNumber;

            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    if(mat[i][j]==0) continue;
                    if(mat[i][j]==-1) continue;
                    if(mat[i][j]==1)
                    {
                        pii b=mp(i,j);
                         int a= makeGroup(b);
                        sizeNumber.push_back(a);
                    }

                }
            }
            int noOfGroups=sizeNumber.size();
            sort(sizeNumber.begin(),sizeNumber.end());
            int maxNumber=*(sizeNumber.end()-1);
            cout<<noOfGroups<<" "<<maxNumber<<endl;
}
int main()
{
    int t,i,j;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        memset(mat,0,sizeof(mat));
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
        //don't use recursive approach as it may casue Runtime error segment fault.
        //solve();
        vector<int> sizeNumber;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(mat[i][j]==0) continue;
                    if(mat[i][j]==-1) continue;
                    if(mat[i][j]==1)
                    {
                        pii b=mp(i,j);
                         int a= makeGroup(b);
                        sizeNumber.push_back(a);
                    }
            }
        }
        int noOfGroups=sizeNumber.size();
            sort(sizeNumber.begin(),sizeNumber.end());
            int maxNumber=*(sizeNumber.end()-1);
            cout<<noOfGroups<<" "<<maxNumber<<endl;

    }
    return 0;
}
/*
This is a graph traversal problem. However, use of a recursive solution should be avoided as it may cause run time error due to
an over flow in the system stack.

This problem can be solved by breadth first search or depth first search. Basically,
it involves finding number of disconnected components in a graph and maximum number of vertices in any component.
*/
