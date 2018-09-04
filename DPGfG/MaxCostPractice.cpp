#include <bits/stdc++.h>
#define N 20
using namespace std;
int MaxCost(int cost[][N],int n)
{
    int tc[n][n];
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==0)
            {
                tc[i][j]=cost[i][j];
            }
            else
            {
                int maxi=0;
                if((j-1)>=0)
                {
                    if(maxi<tc[i-1][j-1])
                    maxi=tc[i-1][j-1];
                }
                if((j+1)<n)
                {
                    if(maxi<tc[i-1][j+1])
                    maxi=tc[i-1][j+1];
                }
                if(maxi<tc[i-1][j])
                maxi=tc[i-1][j];
                tc[i][j]=maxi+cost[i][j];
            }
        }
    }
    /*for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        cout<<tc[i][j]<<"\t";
        cout<<"\n";
    }
    cout<<"\n";*/
    int co=0;
    for(j=0;j<n;j++)
    {
        if(co<tc[n-1][j])
        {
            co=tc[n-1][j];
            //cout<<tc[n-1][j]<<"\t and co is : "<<co<<"\t";
        }

    }
    //cout<<"\n co final : "<<co<<"\n";
    return co;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int i,j,n;
	    cin>>n;
	    int ar[20][20];
	    for(i=0;i<n;i++)
	    for(j=0;j<n;j++)
	    cin>>ar[i][j];
	    int re=MaxCost(ar,n);
	    cout<<re<<"\n";

	}
	return 0;
}
