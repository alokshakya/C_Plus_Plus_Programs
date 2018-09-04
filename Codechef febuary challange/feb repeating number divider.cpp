#include<iostream>
#define boost1 ios_base::sync_with_stdio(0)
#define boost2 cin.tie(0)
#define ll long long int
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        ll n,m;
        cin>>n>>m;
        int d=s.size();
        cout<<"size of numeric "<<d<<endl;
        int si=d*n;
        char num[si];
        int i;
        string alok;
        for(i=0;i<n;++i)
        {
            alok.append(s);
        }
        d=alok.size();
        cout<<"size of numeric "<<d<<endl;

        long long remainder = 0;
for (int i = 0; alok[i] != '\0'; ++i)
    remainder = (remainder * 10 + alok[i] - '0') % m;
cout<<remainder<<endl;


        /*int i,d=0,z=0,r=0;
        z=a;
        while(z>0)
        {
            d++;
            z=z/10;
        }
        cout<<" number of digits "<<d<<endl;
        ll dig[d];
        i=d-1,z=a;
        cout<<" value of z "<<z<<endl;
        while(z>0)
        {
            r=z%10;
            cout<<" value of remainder in loop "<<r<<endl;
            dig[i]=r;
            z=z/10;
            cout<<" value of z in loop "<<z<<endl;
            i--;

        }
        for(i=0;i<d;++i)
        {
           cout<<'dig[i]'<<"  ";
        }

        cout<<endl;*/

    }
    return 0;
}
