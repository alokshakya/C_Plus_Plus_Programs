#include<iostream>
#include<queue>
using namespace std;
#define ll long long
int main()
{
    int i,j,m,n,c,d;
    ll sum=0;
    cin>>m>>n;
    priority_queue<int>Q; // by default max heap is formed.
    for(i=1; i<=m; ++i)
    {
        cin>>c;
        Q.push(c);
    }
    for(j=1; j<=n; ++j)
    {
        d=Q.top();sum+=d; Q.pop();Q.push(d-1);
    }
    cout <<sum<<endl;
    return 0;
    }


