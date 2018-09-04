#include<iostream>
#define boost1 ios_base::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define ll long long int
using namespace std;
int main()
{
    boost1;
    boost2;
    int t;
    cin>>t;
    while(t--)
    {
        ll a;
        cin>>a;
        ll n,m;
        cin>>n>>m;
        ll i;
        ll ar[n];
        ll z=a,x=1;
        while(z>0)
        {
            x=x*10;
            z=z/10;

        }
        for(i=0;i<n;++i)
        {
            ar[i]=a;
        }

        long long remainder = 0;
for (ll i = 0; i<n; ++i)
    remainder = (remainder * x + ar[i] ) % m;
cout<<remainder<<endl;

    }
    return 0;
}
