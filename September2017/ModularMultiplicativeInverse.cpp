#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a==0) return b;
    return gcd(b%a,a);
}
int power(int x,int y,int m)
{
    if(y==0) return 1;
    int p=power(x,y/2,m)%m;
    p=(p*p)%m;
    return (y%2==0)?p:(x*p)%m;
}
int modInverse(int a,int m)
{
    int g=gcd(a,m);
    if(g!=1)
    {
        cout<<"Inverse does not exist "<<endl;
        return -1;
    }
    else
        return power(a,m-2,m);
}
int main()
{
    int a=3,m=1e9+7;
    int inv=modInverse(a,m);
    cout<<"INVERSE is : "<<inv<<endl;
    return 0;
}
