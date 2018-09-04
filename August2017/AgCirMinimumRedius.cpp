#include<bits/stdc++.h>
#define N 100005
#define ll long long
using namespace std;
int arx[N];
int ary[N];
double dist[N];
int main()
{
    int n,k,i;
    cin>>n>>k;
    int x,y;
    memset(arx,0,sizeof(arx));
    memset(ary,0,sizeof(ary));
    for(i=0;i<n;i++)
    {
        cin>>x;
        arx[i]=x;
    }
        for(i=0;i<n;i++)
    {
        cin>>y;
        ary[i]=y;
    }
    for(i=0;i<n;i++)
    {
        ll d=((arx[i]*arx[i])+(ary[i]*ary[i]));
        dist[i]=sqrt(d);
    }
    sort(dist,dist+n);
    double di=dist[k-1];
    cout<<ceil(di)<<endl;
    return 0;
}
