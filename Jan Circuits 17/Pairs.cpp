#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    vector<pair<int,int>> vec;
    vector<pair<int,int>>::iterator it;
    vec.push_back(make_pair(1,2));
    it=find(vec.begin(),vec.end(),make_pair(1,2));
    if(it==vec.end())
    {
     vec.push_back(make_pair(1,2));
    }

    vec.push_back(make_pair(1,2));
    cout<<vec.size()<<endl;
    return 0;
}
