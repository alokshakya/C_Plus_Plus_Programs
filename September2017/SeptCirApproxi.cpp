#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,m;
    cin>>n>>k>>m;
    int mat[m+1][n+1];
    int i,j;
    for(i=1;i<m+1;i++)
    {
        for(j=1;j<n+1;j++)
        {
            cin>>mat[i][j];
        }
    }
    int pro[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>pro[i];
    }


    return 0;
}
