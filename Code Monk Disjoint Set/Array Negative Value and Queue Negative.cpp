#include<iostream>
#include<queue>
using namespace std;
int main()
{
    priority_queue<int> Q;
    int t,i;
    cin>>t;
    for(int i=1;i<t;++i)
        Q.push(i);
    Q.push(-12);
    Q.push(1);
    Q.push(7);
    while(!Q.empty())
    {
        cout<<Q.top()<<endl; Q.pop();
    }

    return 0;
}
