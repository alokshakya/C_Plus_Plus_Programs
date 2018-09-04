#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i=0;i<n;i++)
#define ll long long
#define elif else if
#define ff first
#define ss second
#define pii pair<ll int,ll int>
#define mp make_pair
#define pb push_back
#define CLEAR(array, value) memset(ptr, value, sizeof(array));
#define si(a)     scanf("%d", &a)
#define sl(a)     scanf("%lld", &a)
#define pi(a)     printf("%d", a)
#define pl(a)     printf("%lld", a)
#define pn        printf("\n")


int main()
{
  ios_base::sync_with_stdio(false);
  int t;
  cin>>t;
  while(t--)
  {
    int i,j,n,m;
    cin>>n>>m;
    assert(1<=n && n<=100000);
    assert(1<=m && m<=100000);
    vector<ll int>v(n+m);
    rep(i,n+m){
    cin>>v[i];
    assert(0<= v[i] && v[i]<= 1000000000000);
  }
    set<ll int>mys;
    rep(i,n)
      mys.insert(v[i]);
    for(i=n;i<n+m;i++)
    {
      if(mys.find(v[i])!=mys.end())
        cout<<"YES\n";
      else
        cout<<"NO\n";
      mys.insert(v[i]);
    }
  }
  return 0;
}
