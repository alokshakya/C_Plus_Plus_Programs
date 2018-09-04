#include<bits/stdc++.h>
#define assn(n,a,b) assert(n>=a && n<=b)
#define F first
#define S second
#define mp make_pair
using namespace std;
int main()
{
    int n,i;
    vector < pair < int, int > > ar;
    long long cur=0,ans=0;
    cin >> n;
    ar.resize(n);
    assn(n,1,1e5);
    for(i=0; i<n; i++)
    {
    cin >> ar[i].F >> ar[i].S;
    assn(ar[i].F, 0, 1e9);
    assn(ar[i].S, 1, 1e9);
    }

    sort(ar.begin(),ar.end());
    priority_queue< pair < int, int > , vector< pair < int, int> >, greater<  pair < int, int > > > mheap;
    // elements in heap are sorted according to the first element of pair<int,int>
    i=1;
    mheap.push(mp(ar[0].S,ar[0].F));
    cur=ar[0].F;
    while(!mheap.empty() || i<n)
    {
        while(i<n && ar[i].F<=cur)
            {
               mheap.push(mp(ar[i].S,ar[i].F));
                i++;
            }

               if(mheap.empty() && i<n)
                {
                   cur=ar[i].F;
                     mheap.push(mp(ar[i].S,ar[i].F));
                       i++;
                  }
              pair < int, int > p = mheap.top();
                mheap.pop();
              cur+=(long long)(p.F);
//  printf("cur:%d cook-time:%d coming-time:%d\n",cur,p.F,p.S);
                  ans+=(long long)(cur)-(long long)(p.S);
    }
    cout << ans/n << endl;
    return 0;
}
