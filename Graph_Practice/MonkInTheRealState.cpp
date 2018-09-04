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
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int e,x,y;
        cin>>e;
        int ar[10001]={0};//initialize all elements of array to zero
        for(int j=0;j<e;j++)
        {
            cin>>x>>y;
            ar[x]=1;ar[y]=1;
        }
        int co=0;
        for(int k=1;k<10001;k++)
        {
            if(ar[k]==1)
                co++;
        }
        cout<<co<<endl;
    }
    return 0;
}
