#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int t,i,j,value,x;
    cin>>t;
    while(t--)
    {
 vector<int> an;
int as[50];
int ans[50];
        int s;
        cin>>s;
        for(i=0;i<s;++i)
        {
            cin>>value;
            an.push_back(value);
           // cin>>an[i];
        }
        sort(an.begin(),an.end());
        for(j=s-1;j>=0;--j)
        {
            if(j==s-1)
                as[j]=(an[j]);
            else
                as[j]=(as[j+1]+an[j]);
        }
        for(i=0;i<s;++i){
            ans[i]=as[(s-1)-i];
        }

          int k;
          cin>>k;
          int q[k]; int price[k];
          for(i=0;i<k;++i)
          {
             cin>>x; x--; q[i]=x;
          }

          for(i=0;i<k;++i)
            cin>>price[i];

            for(i=0;i<k;++i)
            {
                if(price[i]<=ans[q[i]])
                {
                   cout<<"Yes"<<endl;
                }

                else
                    cout<<"No"<<endl;
            }


    }
    return 0;
}
