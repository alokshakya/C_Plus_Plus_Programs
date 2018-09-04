#include<iostream>
#include<queue>
#define p pair<int,int>
#define mp make_pair
#define f first
#define s second
using namespace std;
class compareV
{
public:
    bool operator()(p n1,p n2)
    {
        if(n1.f==n2.f)
        return n1.s>n2.s;
        else
            return n1.s<n2.s;
    }
};
int main()
{
    int n,k,i;
    cin>>n>>k;
    priority_queue<p,vector<p>, compareV> Q;
    int a;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        Q.push(mp(a,i));

    }
  //  cout<<"Queue size : "<<Q.size()<<endl;
  i=0;
    while(!Q.empty() && i<k)
    {
        p b=Q.top();
        //cout<<" pop "<<endl;
        //cout<<b.s<<" value : "<<b.f<<endl;
        cout<<b.s<<" ";
        Q.pop();
        if(b.f!=0)
        Q.push(mp(b.f-1,b.s));
        i++;
        cout<<" i th "<<i<<endl;
    }
    return 0;
}
