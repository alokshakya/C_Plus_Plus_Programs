#include<iostream>
#include<queue>
#define ll long long int
using namespace std;
int main()
{
    int n,i,t;
    ll a;
    queue<ll> myq;
    cin>>n;
    for(i=0;i<n;++i)
    {
        cin>>t;
        if(t==1)
        {
            cin>>a;
            myq.push(a);
        }

        if(t==2)
        {
            myq.pop();
        }

        if(t==3)
        {
            cout<<myq.front()<<endl;
        }
    }
    return 0;
}
