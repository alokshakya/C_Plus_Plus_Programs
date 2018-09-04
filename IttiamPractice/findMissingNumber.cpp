#include<bits/stdc++.h>
#define ll long long
#define foreach(v,it) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
using namespace std;
int n;
// you can test upto 25 bit number range
int findMissing(vector<int> ar,int pos)
{
    cout<<"pos "<<pos<<endl;
    if(pos==n) return 0;
    vector<int> odd;
    vector<int> even;
    /*cout<<"elements is position "<<pos<<" are : ";
    foreach(ar,it)
     cout<<*it<<"  ";
    cout<<endl;*/
    vector<int>::iterator it;
    for(it=ar.begin();it!=ar.end();it++)
    {
        if(((*it)&(1<<pos))==0)
           {
               even.push_back(*it);
           }
           else
            {
                odd.push_back(*it);
            }
    }

    if(odd.size()>=even.size())
    {
        return (findMissing(even,pos+1))<<1|0;
    }
    else
        return (findMissing(odd,pos+1))<<1|1;



}
int main()
{
    cout<<"enter no of bits number "<<endl;
    cin>>n;
    int sz=(1<<n);// 2^n
    cout<<"enter number which is not present in range 0 to "<<(sz-1)<<endl;
    int no,i;
    cin>>no;
    while(no>sz-1)
    {
        cout<<"enter number which is not present in range 0 to "<<(sz-1)<<" Only you have entered "<<no<<" which is outside "<<endl;
        cin>>no;
    }
    vector<int> ar;
      //int ar[sz]; //size of array 2^n =1<<n
    for( i=0 ; i < sz; i++)
    {
        //cout<<" i value "<<i<<" ";
        if(i==no) continue;

        ar.push_back(i);
    }
    int mis=findMissing(ar,0);
    cout<<"missing number "<<mis<<endl;
    //long long z=1<<30;
    //cout<<"max value of 30 bit number is "<<endl;
    //cout<<z<<endl;
    return 0;
}
