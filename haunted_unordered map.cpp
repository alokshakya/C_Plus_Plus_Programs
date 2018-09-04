/*
www.hackerearth.com/practice/data-structures/trees/heapspriority-queues/practice-problems/algorithm/haunted
*/
#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<unordered_map>
using namespace std;
#define ll long long
#define p pair<int,int>
class compareV
{
public:
    bool operator()(pair<int,int> n1,pair<int,int> n2) {
        if(n1.second != n2.second)
            return n1.second<n2.second;
        else
         return n1.first< n2.first;
    }
};
int main()
{
    int n, m,age;
    cin>>n>>m;
    int i,j;
    unordered_map<int,int> mymap;
    priority_queue< p, vector<p>, compareV> Q;
       for(i=1; i<=m; ++i)
    {
        mymap[age]=0;
    }
    for(i=1; i<=n; ++i)
    {
        cin>>age;
        mymap[age]=mymap[age]+1;
       // cout<<"value of ts "<<i<<" th time = "<< mymap[age]<<endl;
        //ts+=1;
     //size of map remains same as key is same
       // cout<<"size of mymap in "<<i<<" th time = "<< mymap.size()<<endl;
        Q.push(make_pair(age,mymap[age]));// size of queue inccreases as new value is added it doesn't see key
        cout<<Q.top().first<<" "<<Q.top().second<<endl;
       // cout<<"size of priority_queue Q in "<<i<<" th time = "<< Q.size()<<endl;
    }
    return 0;
}
