/*
www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/haunted
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
    bool operator()(pair<ll,pair<ll, ll>> n1,pair<int,int> n2) {
        if(n1.second.second!=  n2.second.second)
         return n1.second.second<n2.second.second;
         else
            return n1.first < n2.first;
    }
};
int main()
{
    ll n,id,z_c,z_n,p,l,c,s,change_z;
    cin>>n;
    int i,j;
    map<int,int> mymap;
    priority_queue< p, vector<p>, compareV> Q;
       for(i=1; i<=n; ++i)
    {
        cin>>id>>z_c>>p>>l>>c>>s;
        z_n=(50*p + 5*l + 10*c + 20*s);
        change_z=z_n-z_c;
        Q.push(make_pair(id,make_pair(z_n,change_z)));
    }
    for(i=1; i<=5; ++i)
    {
       cout<<Q.top().first<<" "<<Q.top().second.first<<endl;
    }
    return 0;
}
