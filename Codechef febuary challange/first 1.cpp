#include<iostream>
#define boost1 ios::syn_base(0)
#define boost2 cin.tie(0)
#define ll long long int
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,a,i;
        cin>>n;
        int ar[2]={0,0};
        int flag=0,noA=0;
        for(i=0;i<n;++i)
        {
            cin>>a;
            if(a==1 && flag==0)
            {
                noA++;
            }
            if(a!=1)
            {
                flag=1;
            }
            ar[a]++;

        }
        ll fine=0, rent=0, totalRent=0;
            fine=(n-noA)*100;
            rent=(n-(ar[1]))*1000;
            totalRent=fine+rent;
            cout<<totalRent<<endl;


    }
    return 0;
}
