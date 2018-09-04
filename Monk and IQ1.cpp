#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<map>
using namespace std;
#define ll long long
#define p pair<int,int>
int x[100005];
int y[100005];
int z[100005];
class compareV
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        return n1.second>n2.second;
    }
};
int main()
{
    int c , P ,n;
    cin>>c>>P>>n;
    int i,j;
    vector<p> vec;
    p a[100005] ;
    for(i=1; i<=n; ++i)
    {
        cin>>x[i];
    }
        for(i=1; i<=P; ++i)
    {
        cin>>y[i];
    }
       for(i=1; i<=c; ++i)
    {
        z[i]=x[i]*y[i];
        vec.push_back(make_pair(i,z[i]));



    }
    priority_queue< p, vector<p>, compareV> Q(vec.begin(),vec.end());
    int t=0;
    while(!Q.empty() && (t<P) )
    {
        p a=Q.top();
        if(t!=P-1)
        cout<<a.first<<" ";
        else
        cout<<a.first<<endl;
        Q.pop();
        t++;
    }


    return 0;
}
