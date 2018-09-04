#include<iostream>
#include<map>
#include<queue>
using namespace std;
#define p pair<int,int>
class compareV
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {

        return n1.second>n2.second;
    }
};
int main()
{
    int n,m,i,age,ts;
    cin>>n>>m;
    map<int,int> mymap;
    priority_queue<p,vector<p>) Q;
    for(i=1;i<=m;++i)
    {
        Q.push(make_pair(i,0));
        mymap.insert(make_pair(i,0));
    }
    for(i=1; i<=n; ++i)
    {
        cin>>age;
        mymap.find(age)->second+=1;
        //it=mymap.find(age);
        Q.push(*it);
        cout<<Q.top().first<<" "<<Q.top().second<<endl;

    }

    return 0;
}
