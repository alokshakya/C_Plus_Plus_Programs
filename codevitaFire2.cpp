#include<bits/stdc++.h>
#define pii pair<int,int>
#define piib pair<pii,bool>
#define mp(x,y) make_pair(x,y)
#define node(x,y,vi) mp(mp(x,y),vi)
#define f first
#define s second
using namespace std;
char mat[20][20];
int n,m;
int dfs(stack<pii> start)
{
    //cout<<"inside dfs"<<endl;
    vector<pii> dir(8);
            dir[0]=make_pair(-1,0);//N
            dir[1]=make_pair(0,1);//E
            dir[2]=make_pair(1,0);//S
            dir[3]=make_pair(0,-1);//W
            dir[4]=make_pair(-1,1);//NE
            dir[5]=make_pair(1,1);//SE
            dir[6]=make_pair(1,-1);//SW
            dir[7]=make_pair(-1,-1);//NW
    int co=0;
    stack<stack<pii>> st;
    st.push(start);
    //cout<<"start node "<<start.top().f<<"start.top().s "<<start.top().s<<"start.top().size() "<<start.size()<<endl;
    while(!st.top().empty())
    {
       // cout<<"inside first while loop "<<endl;
        stack<pii> top=st.top();
        st.pop();
        //cout<<" top.size() "<<top.size()<<endl;
        stack<pii> st2;
        while(!top.empty())
        {  // cout<<"inside second while loop "<<endl;
            pii t=top.top();
            top.pop();
            int x=t.f; int y=t.s;

            vector<pii>::iterator it;
            for(it=dir.begin();it!=dir.end();it++)
            {
                //cout<<"inside direction loop"<<endl;
                int nx=x+(*it).f;int ny=y+(*it).s;
               // cout<<"nx "<<nx<<"  ny  "<<ny<<endl;
                if(nx<0 && nx>=n) continue;
                if(ny<0 && ny>=m) continue;
                if(mat[nx][ny]=='V') continue;
                if(mat[nx][ny]=='W') continue;
                if(mat[nx][ny]=='T')
                {
                    mat[nx][ny]='V';
                   // cout<<"inside T nx "<<nx<<"  ny  "<<ny<<endl;
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
    //cout<<n<<m;
    cin>>a>>b;
    //cout<<a<<b;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>mat[i][j];
        }
    }
    cout<<"matrix entered "<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<mat[i][j]<<"  ";
        }
        cout<<endl;
    }

    stack<pii> start;
  //  --a;--b; // since we are using 0 index while question uses 1 index
    start.push(make_pair(a,b));
   int result=0;
   result=dfs(start);
   cout<<result<<endl;
    return 0;
}
