#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> an;
vector<int> as;
vector<int> ans;
int main()
{
    int t,i,j;
    cin>>t;
    cout<<endl;
    while(t--)
    {
        int s=5;
       // cin>>s;
        for(i=0;i<s;++i)
        {
            an.push_back(i+1);
           // cin>>an[i];
        }
        sort(an.begin(),an.end());
        for(j=0;j<s;++j)
        {
            if(j==0)
                as.push_back(an[j]);
            else
                as.push_back(as[j-1]+an[j]);
        }
        for(i=(s-1);i>=0;--i)
            ans.push_back(as[i]);
       // for(j=0;j<s;++j)
          //  cout<<ans[j]<<endl;

          int k;

    }
    return 0;
}
