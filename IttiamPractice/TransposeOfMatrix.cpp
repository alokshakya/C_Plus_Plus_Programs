#include<bits/stdc++.h>
using namespace std;

template< typename T, size_t N, size_t M >
void printArray( T(&theArray)[N][M]  ) {
    for ( int x = 0; x < N; x ++ ) {
        for ( int y = 0; y < M; y++ ) {
            cout << theArray[x][y] << " ";
        }
        cout<<"\n";
    }
}
void transpose(int ar[][10],int r,int c)
{
    int i,j;
    int tar[c][r];
    int n=r; int m=c;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            tar[j][i]=ar[i][j];
        }
    }
    //how to assign value of tar to ar
}
void printArray(int ar[][10],int  r,int c)
{
    int i,j;
    int n=r; int m=c;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cout<<ar[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    int n,m,i,j;
    cin>>n>>m;
    int ar[n][m];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            cin>>ar[i][j];
        }
    }
   printArray( ar,n ,m );
    int tar[m][n];
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            tar[j][i]=ar[i][j];
        }
    }
    //print transpose
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<tar[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
