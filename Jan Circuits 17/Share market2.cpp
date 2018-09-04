#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> an;
int as[50];
int ans[50];
int main()
{
    int t,i,j,value,x;
    cin>>t;
    while(t--)
    {
        int s=50;
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

         for(j=0;j<s;++j)
          cout<<ans[j]<<" this is answer at "<<j<<"th position "<<endl;

          int k;
          cin>>k;
          int q[k]={0}; int price[k]={0};
          for(i=0;i<k;++i)
          {
             cin>>x; x--; q[i]=x;
          }
          cout<<"indexes of query"<<endl;
          for(i=0;i<k;++i)
            cout<<q[i]<<endl;

          for(i=0;i<k;++i)
            cin>>price[i];

            for(i=0;i<k;++i)
            {
                 cout<<"price["<<i<<"] = "<<price[i]<<" and "<<"ans[q["<<i<<"]-1] = "<<ans[q[i]]<<endl;
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
