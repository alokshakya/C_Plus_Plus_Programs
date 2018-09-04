#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
int main()
{
    int n;
    cin>>n;
    int ar[n+1];
    int i;
    for(i=1;i<=n;i++)
        cin>>ar[i];
    int gcds[n+1];
    for(i=n;i>=1;i--)
    {
        if(i==n)
        {
            gcds[i]=ar[n];
        }
        else
            gcds[i]=gcd(gcds[i+1],ar[i]);
    }
    int maxi=0, index=0;
    for(i=1;i<n;i++)
    {

        if(maxi<gcds[i])
        {
            //cout<<"gcd["<<i<<"] is : "<<gcds[i]<<" and maxi : "<<maxi<<endl;
            maxi=gcds[i];
            index=i;

        }
    }
    cout<<index-1<<endl;

    return 0;
}
