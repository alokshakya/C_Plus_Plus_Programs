#include<bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin>>q;
    while(q--)
    {
        int n,i;
        set<int> s;
        cin>>n;
        int ar[n];
        int ar2[n];
        for(i=0;i<n;i++)
        {
            int a;
            cin>>a;
            ar[i]=a;
            s.insert(a);
        }
        //check for 1to n
        int flag1=0,flag2=0,flag3=0;
        for(i=0;i<n;i++)
        {
            if(ar[i]<1 || ar[i]>n)
            {
                flag1=1;
                break;
            }
        }
        // check for uniquness

        if(n!=s.size())
            flag2=1;
        for(i=1;i<n-1;i++)
        {

            if(ar[i]>ar[i+1])
            {
                flag3=1;
                break;
            }
        }

        if(flag1==0 && flag2==0 && flag3==1)
        {
            cout<<"Beautiful"<<endl;
        }
        else
            cout<<"Ugly"<<endl;
    }
    return 0;
}
