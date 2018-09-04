#include<iostream>
using namespace std;
void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i)? cout<<("1"): cout<<("0");
}
int main()
{
    unsigned int n;
    cin>>n;
    cout<<"Binary representaion of "<<n<<" is : ";bin(n);
    return 0;
}
