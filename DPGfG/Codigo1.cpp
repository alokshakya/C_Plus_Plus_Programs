#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        if(n%4==0)
            cout<<"HAPPY"<<"\n";
        else
            cout<<"SAD"<<"\n";
    }

    return 0;
}
