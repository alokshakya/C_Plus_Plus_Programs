#include<iostream>
using namespace std;
void swap1(int *x, int *y)
{
    cout<<"hell"<<endl;
    cout<<x<<" alsl  " <<y<<endl;
    int temp=*x;
    *x=*y;
    *y=temp;

}
int main()
{
    int a=3,b=4;
    swap1(&a,&b);
    cout<<a<<" "<<b<<endl;
    return 0;
}
