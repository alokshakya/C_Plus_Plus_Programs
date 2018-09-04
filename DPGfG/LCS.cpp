#include<bits/stdc++.h>
using namespace std;
int LCS(char *str1, char *str2,int n1,int n2)
{
    int L[n1+1][n2+1];
    int i,j;
    for(i=0;i<=n1;++i)
    {
        for(j=0;j<=n2;++j)
        {
            if(i==0 || j==0)
                L[i][j]=0;
            else if(str1[i-1]==str2[j-1])
                L[i][j]=L[i-1][j-1]+1;
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    }
    return L[n1][n2];
}
int main()
{
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    int res=LCS(X,Y,m,n);
    cout<<res<<"\n";
    return 0;
}
