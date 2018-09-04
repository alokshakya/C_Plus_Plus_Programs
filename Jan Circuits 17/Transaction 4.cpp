#include<iostream>
#include<map>
#include<vector>
#define p pair<int,int>
#define mp make_pair
using namespace std;
int main()
{
    int t,q,i,a,c,d;
    cin>>t>>q;
    vector<p> vec;
    map<int,int> mymap;
    map<int,int>::iterator it;
    for(i=1;i<=t;++i)
    {
        cin>>a;
        mymap[i]=a;

    }
    //query execution
    for(i=1;i<=q;++i)
    {
        cin>>c>>d;
        for(it=mymap.find(c);it!=mymap.end();++i)
        {
            if(it->second>=c)
                cout<<it->second;
        }
    }


    return 0;
}
