#include<iostream>
using namespace std;
int swapEvenOddBits(int x)
{
return ( ((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1) );
// 5 is 0101 so 5 8 times means 4*8 32 bit
// a=10 is 1010 so a 8 times means 4*8 32 bit so above is applicable for 32 bit numbers
//suppose for x=5 which is 0101
// for 5&1010 0101&1010=0000>>1=0000
// 5&5        0101&0101=0101<<1=1010
// 0000|1010=1010 this would be answer which is 10
}
int swapEvenOddBitsfor8Bits(int x)
{
return ( ((x & 10101010) >> 1) | ((x & 01010101) << 1) );// mask even bits with 10101010 then right shift to make them odd
// mask odd bits with 01010101 then left shift to make them even this only applicable for 8 bits number
}
int main()
{
    int n;
    cin>>n;
    int m=swapEvenOddBits(n);
    cout<<m<<endl;
    return 0;
}
