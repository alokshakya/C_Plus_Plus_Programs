#include<iostream>
#include<queue>
#include<vector>
#include<functional>
using namespace std;
#define ll long long
int main()
{
    ll a,b,c,in;
  //  priority_queue<ll, greater> Q1;
    int i,j,n;
    cin>>n;
    vector<int> vec;
    int number[n];
    for(i=1; i<=n; ++i)
    {
        cin>>in;
        vec.push_back(in);
      //  number[i]=in;
    }
    for(i=1; i<=n; ++i)
    {
         priority_queue<int, vector<int>> Q(vec.begin(),vec.begin()+i);
        // priority_queue<int, vector<int>> Q;
         //Q.swap(Q1);
        // cout<<"contents of Queue in "<<i<<" th iteration "<<endl;

         if(Q.size()<3)
            cout<<"-1"<<endl;
         else
         {
             a=Q.top(); Q.pop();
             b=Q.top(); Q.pop();
             c=Q.top(); Q.pop();
             cout<<a*b*c<<endl;
         }
         //Q.clear();
    }
    return 0;
}
