#include<iostream>
#include<set>
#define ll long long
using namespace std;
int main()
{
    int t,n,x,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        set<ll> myset;
        ll a;
        for(i=1;i<=n;++i)
        {
            cin>>a;
            myset.insert(a);

        }
        if(myset.size()>x)
            cout<<"Average"<<endl;
        else if(myset.size()<x)
            cout<<"Bad"<<endl;
        else
            cout<<"Good"<<endl;
    }

    return 0;
}
