#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ar[n];
    int i;
    for(i=0;i<n;i++)
        cin>>ar[i];
    int ans[100005];
    for(i=0;i<100005;i++)
        ans[i]=0;
    for(i=0;i<n;i++)
    {
        for(int j=1;j*j<=ar[i];j++)
        {
            if(ar[i]%j==0)
            {
                if(j*j==ar[i])
                {
                    ans[j]++;
                }
                else
                {
                    ans[j]++;
                    ans[ar[i]/j]++;
                }
            }
        }

    }
    int q;
    cin>>q;
    while(q--)
    {
        int k;
        cin>>k;
        cout<<ans[k]<<endl;
    }
    return 0;
}
