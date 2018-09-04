#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x,a;
        cin>>n>>x;
        priority_queue<int, vector<int>, greater<int> > pq;
        for(int i=0;i<n;i++)
          {
              cin>>a;
              pq.push(a);
          }
          int cnt=0;
          while(!pq.empty())
          {
              int to=pq.top(); pq.pop();
              if(x<to)
              {
                  break;
              }
              if(to<=x)
              {
                  cnt++;
                  x=x-to;
              }
          }
          cout<<cnt<<endl;
    }
    return 0;
}
