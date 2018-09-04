#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=1;i<=n;i++)
        cin>>a[i];
        int sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i];
    int avg=sum/n;
    cout<<(avg+1)<<endl;
    return 0;
}
