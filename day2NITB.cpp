#include<bits/stdc++.h>
using namespace std;

int main()
{

int ap=1000000008;
cout<<ap<<endl;
    int n,q;
    cin>>n>>q;
    char nameP[n];
    char b[n];
    int i;
    for(i=0;i<n;++i)
        cin>>nameP[i];
        int t,index,pre,flag=0;
        char ch;
    while(q--)
    {
        cin>>t;
        if(t==1)
        {

            cin>>index>>ch;
            nameP[index-1]=ch;

            strcpy(b,nameP);

            if(nameP[index-1] > nameP[index-2] && nameP[index-1]< nameP[index] && nameP[index-1]> nameP[0])
                flag=1;
                pre=1;


        }
        else
        {
            cin>>index;

            if(pre==2 || flag==1)
            {
                cout<<nameP[index-1]<<endl;
            }
            else
            {


              //  b=arrange(nameP, n);
                sort(b,b+n);
                cout<<b[index-1]<<endl;
            }
            pre=2;
        }

    }

    return 0;
}
