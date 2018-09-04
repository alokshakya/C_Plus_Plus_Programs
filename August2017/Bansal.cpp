#include<bits/stdc++.h>
#define pii pair< int, int >
#define vi vector < int >
#define vii vector<pii>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define foreach(v,it) for( __typeof((v).begin())it = (v).begin() ; it != (v).end() ; it++ )
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define dbg2(x,y) { cout<< #x << ": " << (x) << " , " << #y << ": " << (y) << endl; }
#define all(x) x.begin(),x.end()
#define mset(x, v) memset(x, v, sizeof(x))
#define N 100005
using namespace std;
int main()
{
 int t;
 cin>>t;
 while(t--)
 {
     int n,q,i;
     cin>>n>>q;
     ll ar[n+1];
     for(i=1;i<=n;i++)
        cin>>ar[i];
     for(i=0;i<q;i++)
     {
         int a;
         cin>>a;
         if(a==2)
         {
             int ind,val;
             cin>>ind>>val;
             ar[ind]=val;
         }
         if(a==1)
         {
             int d;
             cin>>d;
             ll sum=0;
             for(i=d;i<=n;i+=d)
             {
                 sum=(sum+((ar[i]*ar[i])%MOD))%MOD;
             }
             cout<<sum<<endl;
         }
     }
 }
    return 0;
}
