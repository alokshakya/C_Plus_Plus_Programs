#include<bits/stdc++.h>
#define ll long long
using namespace std;
//ll x_value[100000000];
//ll x_valueNext[99999999];
//ll n_value[100000000];
//ll n_valueNext[99999999];
vector<ll> xVal;
vector<ll> nVal;
void initial()
{
    for(ll i=0; i<1000000001; i++)
    {
       if(i==0)
       {
           //x_value[i]=2;
           //n_value[i]=2;
           xVal.push_back(2);
           nVal.push_back(2);
       }
       else
       {
           if(i%2!=0)
           {
               //x_value[i]=x_value[i-1]-((i)*(i+1));
               //n_value[i]=x_value[i-1];
               ll a=xVal[i-1];
               xVal.push_back(a-(((i)*(i+1))));
               nVal.push_back(a);

           }
           else
           {
               x_value[i]=x_value[i-1]+((i)*(i+1));
               n_value[i]=x_value[i];

           }

       }
       //cout<<"value of i "<<i<<endl;
    }
    // next loop for storing next elements
  /*  for(ll i=1; i<100000; i++)
    {


           if(i%2==0)
           {
               x_value[i]=x_value[i-1]-((i)*(i+1));
               n_value[i]=x_value[i-1];

           }
           else
           {
               x_value[i]=x_value[i-1]+((i)*(i+1));
               n_value[i]=x_value[i];

           }


       //cout<<"value of i "<<i<<endl;
    } */

}
int main()
{
    initial();
    int t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        ll n;
        cin>>n;
        cout<<nVal[n-1]<<endl;
    }
    return 0;
}
