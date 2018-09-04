#include<iostream>
#include<map>
#include<queue>
using namespace std;
#define p pair<int,int>
int main()
{
    int n,m,i,age,ts;
    cin>>n>>m;

    map<int, int> mymap;
    priority_queue<int> Q;
    for(i=1;i<=m;++i)
    {
        mymap.insert(p(i,0));
    }
    for(i=1; i<=n; ++i)
    {
        cin>>age;
        mymap.find(age)->second+=1;
        Q.push(mymap.find(age)->second);
        cout<<Q.top()<<endl;

    }

    return 0;
}
