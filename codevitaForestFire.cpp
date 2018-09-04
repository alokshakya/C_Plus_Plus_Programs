#include<bits/stdc++.h>
#define pii pair<int,int>
#define piib pair<pii,bool>
#define mp(x,y) make_pair(x,y)
#define node(x,y,vi) mp(mp(x,y),vi)
#define f first
#define s second
using namespace std;
int mat[20][20];
int n,m;
int dfs(piib start)
{
    int co=0;
    stack<piib> st;
    st.push(start);
    while(!st.empty())
    {
        piib top=st.top();
        st.pop();
        int x=top.f.f;
        int y=top.f.s;
        bool visited=top.s;
        // Check to ensure that we are within the bounds of the grid, if not, continue
        if (x < 0 || x >= n) continue;
        // Similar check for y
       if (y < 0 || y >= m) continue;
       // Check that we haven't already visited this position, as we don't want to count it twice
        if (mat[x][y]=='V') continue;
        mat[x][y] = 'V' // Record that we have visited this node


              co++;

              // Now we know that we have at least one empty square, then we will attempt to
              // visit every node adjacent to this node.
              s.push(node(x + 1, y));
              s.push(node(top.x - 1, top.y));
              s.push(node(top.x, top.y + 1));
              s.push(node(top.x, top.y - 1));

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
    piib start;
    start=node(a,b,false);
    //cout<<"start.f.f "<<start.f.f<<"    start.f.s   "<<start.f.s<<" start.s "<<start.s<<endl;
   int result=0;
   result=dfs(start);
   cout<<result<<endl;
    return 0;
}
