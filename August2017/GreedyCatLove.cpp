#include<bits/stdc++.h>
#define ll long long
#define boost {ios_base::sync_with_stdio(false); cin.tie(NULL);}
using namespace std;
const ll N=1000005;
int cat[N];
int pack[N];
int n;
void fastscan(int &x)
    {
        bool neg=false;
        register int c;
        x =0;
        c=getchar();
        if(c=='-')
        {
            neg = true;
            c=getchar();
        }
        for(;(c>47 && c<58);c=getchar())
            x = (x<<1) + (x<<3) +c -48;
        if(neg)
            x *=-1;
    }
int main()
{
    boost;
    cin>>n;
    //fastscan(n); gives wrong answer
    ll i,j;
    for(i=0;i<n;i++)
        cin>>cat[i];
    for(i=0;i<n;i++)
        cin>>pack[i];
    sort(cat,cat+n);
    sort(pack,pack+n);
    ll sum=0;
    for(i=0;i<n;i++)
        sum+=(cat[i]*pack[i]);
    cout<<sum<<endl;

    return 0;
}
