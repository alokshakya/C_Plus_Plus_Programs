#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>                   // Solution is correct but giving TLE 1.0015
                                  //time limit is 1.0000 sec
using namespace std;
int an[100005];

int main()
{
    ios::sync_with_stdio(false);
    int n,i,j;
    vector<pair<int,int>> vec;
    vector<pair<int,int>>::iterator it;
    cin>>n;

    for(i=1;i<=n;++i)
    {
        cin>>an[i];
    }
    // sub array making part
    for(i=1;i<=n;++i)
    {
        priority_queue<int> Q;
        Q.push(an[i]);
        for(j=i+1;j<=n;++j)
        {
            Q.push(an[j]);
                int a,b;
                a=Q.top(); Q.pop();
                b=Q.top();
                it=find(vec.begin(),vec.end(),make_pair(a,b));
                if(it==vec.end())
                   {
                      cout<<a<<" , "<<b<<endl;
                     vec.push_back(make_pair(a,b));
                   }
               Q.push(a);
        }
    }
    cout<<vec.size()<<endl;
    return (0);
}
