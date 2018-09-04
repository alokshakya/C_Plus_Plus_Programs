#include <bits/stdc++.h>
using namespace std;
int min(int x, int y, int z)
{
    return min(min(x, y), z);
}
int editDistance(string str1,string str2, int n1,int n2)
{
    int D[n1+1][n2+1];
    //cout<<str1<<" "<<str2<<endl;
    int i,j;
    for(i=0;i<=n1;i++)
    {
        for(j=0;j<=n2;j++)
        {
            D[i][j]=0;
            if(i==0)
            D[i][j]=j;
            else if(j==0)
            D[i][j]=i;
            else if(str1[i-1]==str2[j-1])
            D[i][j]=D[i-1][j-1];
            else
            D[i][j]=1+min(D[i-1][j],D[i][j-1],D[i-1][j-1]);
        }
    }
    for(i=0;i<=n1;i++)
    {
        for(j=0;j<=n2;j++)
            cout<<D[i][j]<<"\t";
        cout<<"\n";
    }
    return D[n1][n2];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n1,n2;
	    cin>>n1>>n2;
	    string s1,s2;
	    cin>>s1;
	    cin>>s2;
	    int re=editDistance(s1,s2,n1,n2);
	    cout<<re<<"\n";
	}
	return 0;
}
