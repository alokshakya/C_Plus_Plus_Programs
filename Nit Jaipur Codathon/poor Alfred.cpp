#include<iostream>
using namespace std;
int main()
{



    int t;
    cin>>t;
    while(t--)
    {
        int n,a,b;
        cin>>n>>a>>b;
        int Mn,Mx,i;
        if(a<b)
        {
            Mn=a;
            Mx=b;
        }
        else
        {
            Mn=b;
            Mx=a;
        }
        int op=0;
        if(a==b)
            cout<<(n-1)*a<<endl;
        else
        {
        for(i=0;i<n;++i)
        {
           op=(((n-1)-i)*Mn)+(i*Mx);
           cout<<op<<" ";
        }
        cout<<endl;

        }

    }
    return 0;
}
