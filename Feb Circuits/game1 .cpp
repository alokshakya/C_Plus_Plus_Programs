#include<iostream>
using namespace std;
int main()
{
    //char grid[100000009][3]; can't make grid of size 10^9
    int t,i,j;
    cin>>t;
    while(t--)
    {
        int n,q;
        cin>>n>>q;
        char grid[n][3];
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=3;j++)
                grid[i][j]='.';
        }
        int x,y;
        for(i=1;i<=q;++i)
        {
            cin>>x>>y;
            grid[x][y]='x';
        }
        int ans=0;
        int flag=0;
        for(i=2;i<=n;++i)
        {
            for(j=1;j<=3;j++)
            {
                if(j==1)
                {
                    if(grid[i+1][j]=='x' && grid[i+1][j+1]=='x')
                    {
                        ans=i;
                        flag=1;
                        break;
                    }
                }
                else if(j==2)
                {
                    if(grid[i+1][j]=='x' && grid[i+1][j+1]=='x' && grid[i+1][j-1]=='x')
                    {
                        ans=i;
                        flag=1;
                        break;
                    }
                }
               else if(j==3)
                {
                    if(grid[i+1][j]=='x' && grid[i+1][j-1]=='x')
                    {
                        ans=i;
                        flag=1;
                        break;
                    }
                }

            }
            if(flag==1)
                cout<<"flag is "<<flag<<endl;

        }
        cout<<ans<<endl;
    }
    return 0;
}
