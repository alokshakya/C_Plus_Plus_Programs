#include<bits/stdc++.h>
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define f first
#define s second
using namespace std;
char mat[20][20];
int n,m;
int dfs(stack<pii> start)
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
    int co=0;
    stack<stack<pii>> st;
    st.push(start);
    while(!st.top().empty())
    {
       // cout<<"inside first while loop "<<endl;
        stack<pii> top=st.top();
        st.pop();
        stack<pii> st2;
        while(!top.empty())
        {
            pii t=top.top();
            top.pop();
            int x=t.f; int y=t.s;
            vector<pii>::iterator it;
            for(it=dir.begin();it!=dir.end();it++)
            {
                int nx=x+(*it).f;int ny=y+(*it).s;
                if(nx<0 && nx>=n) continue;
                if(ny<0 && ny>=m) continue;
                if(mat[nx][ny]=='V') continue;
                if(mat[nx][ny]=='W') continue;
                if(mat[nx][ny]=='T')
                {
                    mat[nx][ny]='V';
                    st2.push(mp(nx,ny));
                }
            }
        }

        st.push(st2);
        co++;

    }
    return co;
}
int main()
{
    int a,b,i,j;
    cin>>n>>m;
    cin>>a>>b;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    stack<pii> start;
    --a;--b; // since we are using 0 index while question uses 1 index
    start.push(make_pair(a,b));
   int result=0;
   result=dfs(start);
   cout<<result<<endl;
    return 0;
}
