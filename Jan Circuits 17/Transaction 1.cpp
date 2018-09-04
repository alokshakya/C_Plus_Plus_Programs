#include<iostream>
using namespace std;
int ar[100007];
int main()
{
    int t,q,m,n,i;
    cin>>t>>q;
    for(i=1;i<=t;++i)
    {

        cin>>ar[i];
    }
    for(int j=1;j<=q;++j)
    {
        cin>>m>>n;
        int k=1;
        int h=1;
        for(i=1;i<=t;++i)
        {
            if(ar[k]>=m)
            {
                h++;
            }
            if(h==n && ar[k]>=m)
            cout<<ar[k]<<endl;
            if(h==n && ar[k]<m)
                cout<<"-1"<<endl;
            k++;
        }


    }
    return 0;
}
