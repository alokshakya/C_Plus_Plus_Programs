#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int t,q,i,a,m,n;
    vector<int> vec;
    cin>>t>>q;
    for(i=0;i<t;++i)
    {
        cin>>a;
        vec.push_back(a);
    }

  //  stable_sort(vec.begin(),vec.end());
    for(i=0;i<q;++i)
    {
        cin>>m>>n;
        vector<int>::iterator it;
        it=find(vec.begin(),vec.end(),m);
        while(it<vec.end() && j<n)
        {
            if(*it>n)
            {


            }
        }
        if((it+n-1)<vec.end())
            cout<<*(it+n-1)<<endl;
        else
            cout<<"-1"<<endl;
        //cout<<*(it+n-1)<<endl;
    }

    return 0;
}
