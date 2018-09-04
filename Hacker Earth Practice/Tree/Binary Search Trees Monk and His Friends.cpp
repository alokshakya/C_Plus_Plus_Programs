#include<iostream>
#include<set>
#include<vector>
#include<cassert>
#define ll long long
#define rep(i,n) for(i=0;i<n;i++)
#define repn(i,n,m) for(i=n;i<n+m;i++)
#define boost1 ios_base::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define ass(v) assert(0<= v && v<= 1000000000000)
using namespace std;
int main()
{
    boost1; boost2;
    int t,n,m,i;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a;
        vector<ll int> vec(n+m); // pre defined size of vector
        rep(i,n+m)
        {
            cin>>vec[i];
            ass(vec[i]);
        }
        set<ll int> myset;
        rep(i,n)
        myset.insert(vec[i]);
        repn(i,n,m)
        {
            if(myset.find(vec[i])!=myset.end())
                cout<<"YES\n";
            else
                cout<<"NO\n";
            myset.insert(vec[i]);
        }
    }
    return 0;
}
