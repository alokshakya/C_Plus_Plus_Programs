#include<iostream>
using namespace std;
int main()
{
    int t,i;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int ar[1001];
        int a;
        for(i=0;i<=1000;++i)
            ar[i]=0;
        for(i=1;i<=n;++i)
        {
            cin>>a;
            ar[a]++;
        }
        int co=0;
        for(i=1;i<=1000;++i)
        {
            co+=(ar[i]/2);
        }
        cout<<co<<endl;
    }
    return 0;
}
