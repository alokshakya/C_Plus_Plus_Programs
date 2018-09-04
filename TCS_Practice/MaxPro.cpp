#include<bits/stdc++.h>
#define vi vector < int >
#define pii pair < int , int >
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define foreach(it,v) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define all(x) x.begin(),x.end()
#define mset(x,v) memset(x, v, sizeof(x))
#define sz(x) (int)x.size()
using namespace std;
int main()
{
    int n,pr,cmp;
    cin>>n>>pr>>cmp;
    int ar1[n];
    int ar2[n];
    int i,j;
    for(i=0;i<n;i++)
        cin>>ar1[i];
    for(i=0;i<n;i++)
        cin>>ar2[i];

    int maxi=0;
    for(i=0;i<n;i++)
    {

        if(maxi<(ar1[i]*ar2[i]))
        {
            maxi=(ar1[i]*ar2[i]);
        }
    }
    int ans;
    if(maxi<cmp)
    {
        ans=cmp*pr;
    }
    else
        ans=maxi*pr;
    cout<<ans<<"\n";
    return 0;
}
