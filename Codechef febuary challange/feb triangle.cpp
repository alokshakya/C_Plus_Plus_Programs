/*
This code is contributed by alok_shakya
*/
#include<iostream>
#define boost1 ios_base::sync_with_stdio(0)
#define boost2 cin.tie(0)
using namespace std;
int main()
{
    boost1;
    boost2;
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,co,coun=0;
        cin>>n;
        for(i=1;i<n/2;++i)
        {
            co=n-(2*i+1);
            coun+=(co*(co+1))/2;
        }
        cout<<coun<<endl;
    }
    return 0;
}
