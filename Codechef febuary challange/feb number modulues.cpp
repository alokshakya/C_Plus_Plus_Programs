/*
This code is contributed by alok_shakya
523 3 11 output should be 6. means remainder of 523523523 when divided by 11.
*/
#include<iostream>
#define ll long long int
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,n,m;
        cin>>a>>n>>m;
        ll temp=0,r=0,x=1,z=a;
        while(z>0)
        {
            x*=10;
            z=z/10;
        }
        //cout<<"value of x : "<<x<<endl;
        for(int j=0;j<n;++j)
        {
            temp=a+r*x;
            //cout<<"value of temp : "<<temp<<endl;
            r=temp%m;
           // cout<<"value of r : "<<r<<endl;
        }
        cout<<r<<endl;
    }
    return 0;
}
