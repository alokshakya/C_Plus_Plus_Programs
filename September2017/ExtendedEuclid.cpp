/*
You are given four integers, namely A, B, C, and M. The GCD of C and M is 1.

Write a program to find the value of the following expression:

(
A
B
C
)
%
M
(ABC)%M
Input format

First line: Four space-separated integers A, B, C, and M
Output format

Print the value of the expression.

Constraints

1
≤
A
,
B
,
C
,
M
≤
10
9
1≤A,B,C,M≤109
*/

#include <iostream>
#define ll long long
using namespace std;
ll power(ll x,ll n, ll M)
{
    if(n==0) return 1;
    else if(n%2==0)
      return power((x*x)%M,n/2,M);
    else
      return (x*power((x*x)%M,(n-1)/2,M))%M;
}
ll d, x, y;
void extendedEuclid(ll A, ll B) {
    if(B == 0) {
        d = A;
        x = 1;
        y = 0;
    }
    else {
        extendedEuclid(B, A%B);
        ll temp = x;
        x = y;
        y = temp - (A/B)*y;
    }
}
ll modInverse(ll A, ll M)
{
    extendedEuclid(A,M);
    return (x%M+M)%M;    //x may be negative
}
int main()
{
    ll a,b,c,M;
    cin>>a>>b>>c>>M;
    ll ab=power(a,b,M);
    ll inv=modInverse(c,M);
    ll ans=(ab*inv)%M;
    cout<<ans<<"\n";
    return 0;
}
