#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
#define ll long long
int ar[100005];
int main()
{
    ll a,b,c,in;
    int i,j,n;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>ar[i];
    }
    priority_queue<int> Q;
    for(i=1; i<=n; ++i)
    {
         if(i<3)
         {
            cout<<"-1"<<endl;
            Q.push(ar[i]);
         }

         else
         {
             Q.push(ar[i]);
             a=Q.top(); Q.pop();
             b=Q.top(); Q.pop();
             c=Q.top(); Q.pop();
             cout<<a*b*c<<endl;
             Q.push(c);
             Q.push(b);
             Q.push(a);
         }
    }
    return 0;
}
