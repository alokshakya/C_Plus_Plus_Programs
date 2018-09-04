/*
www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/roy-and-trending-topics-1
*/
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<map>
using namespace std;
#define ll long long
#define p pair<ll,pair<ll,ll>>
class compareV
{
public:
    bool operator()(p n1,p n2) {
        if(n1.second.second != n2.second.second)
            return n1.second.second<n2.second.second;
        else
         return n1.first< n2.first;
    }
};
int main()
{
    ll n,id,z_c,z_n,P,l,c,s,change_z;

    cin>>n;
    int i,j;
    priority_queue< p, vector<p>, compareV> Q;
       for(i=1; i<=n; ++i)
    {
        cin >> id>> z_c>> P>> l>> c>> s;
        z_n=(50*P + 5*l + 10*c + 20*s);
        change_z=z_n-z_c;
        Q.push(make_pair(id,make_pair(z_n,change_z)));

    }
    for(i=1; i<=5; ++i)
    {
       cout<<Q.top().first<<" "<<Q.top().second.first<<endl;
       Q.pop();
    }
    return 0;
}
