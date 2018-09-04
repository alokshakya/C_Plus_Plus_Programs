#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>                   // Solution is correct but giving TLE 1.0015
                                  //time limit is 1.0000 sec
using namespace std;
int an[100005];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
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
       // priority_queue<int> Q;
        //int ar[100007];
        int Max=0,smax=0;
       // ar[i]=an[i];
        Max=an[i];

        //Q.push(an[i]);
        for(j=i+1;j<=n;++j)
        {
            //Q.push(an[j]);
            if(an[j]>Max)
            {
                smax=Max;
                Max=an[j];

            }

                it=find(vec.begin(),vec.end(),make_pair(Max,smax));
                if(it==vec.end())
                   {
                      //cout<<Max<<" , "<<smax<<endl;
                     vec.push_back(make_pair(Max,smax));
                   }
        }
    }
    cout<<vec.size()<<endl;
    return 0;
}
