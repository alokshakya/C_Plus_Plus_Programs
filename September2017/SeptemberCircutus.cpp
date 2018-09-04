#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int i;
        int ar[n];
        for(i=0;i<n;i++)
        {
            cin>>ar[i];
        }
        int cnt=0;
        for(i=0;i<n;i++)
        {
            while(ar[i]%2==0)
            {
                cnt++;
                ar[i]=ar[i]/2;
            }
        }
        int r=cnt%2;
        if(r==0)
        {
            cout<<"Alan"<<endl;
        }
        else
        {
            cout<<"Charlie"<<endl;
        }
    }
    return 0;
}
