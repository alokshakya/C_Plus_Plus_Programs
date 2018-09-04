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
    int n,i;
    string n1;
    getline(cin,n1);

    string ar[n];
    for(i=0;i<n;i++)
    {
        getline(cin,ar[i]);
    }
    int key;bool reversed; string cmp_type;
    string s2;
    getline(cin,s2);
        for(i=0;i<n;i++)
        cout<<ar[i]<<"\n";
    return 0;
}
