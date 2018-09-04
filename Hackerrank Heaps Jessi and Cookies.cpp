/*
If frequent operation is insertion and deletion and finding minimum and maximum
in a data structure use set instead of priority_queue it will be efficient that modified form of
priority_queue.
*/

#include<iostream>
#include<set>
#include<queue>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
    int n,k,i,a,b;
    cin>>n>>k;
   // set<int> Q;
   priority_queue<int,vector<int>,greater<int>> Q;
   // set<int>::iterator it;
    for(i=1;i<=n;++i)
    {
        cin>>a;
        Q.push(a);
    }
    int co=0;
    while(Q.top()<k && Q.size()>=2)
    {
        a=Q.top(); Q.pop();b=Q.top(); Q.pop();
        cout<<"a = "<<a<<" b = "<<b<<endl;
        int s=(1*a)+(2*b);
        cout<<"1*a + 2*b = "<<s<<endl;
        Q.push(s);
        co++;
    }
    while(!Q.empty())
    {
       cout<<Q.top()<<endl; Q.pop();
    }

    if(Q.top()<k && Q.size()==1)
        co=-1;
    cout<<co<<endl;

return 0;
 }
