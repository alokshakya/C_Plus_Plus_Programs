#include<iostream>
#include<climits>
#define ll unsigned long long int
#define Max ULLONG_MAX
using namespace std;
int main()
{
    ll a[3];
    int i;
    ll cou=0;
    for(i=0;i<3;i++)
        cin>>a[i];
    ll min=Max;
   //cout<<"min = "<<min<<endl;
    for(i=0;i<3;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
        }
    }
  //  cout<<"min = "<<min<<endl;
cou=min;
  for(i=0;i<3;i++)
    a[i]=a[i]-min;
    ll c;
  for(i=0;i<3;i++)
  {
      if(a[i]==0) continue;

      c+=a[i];
     // ll b=a[i]%2;
//if(b==1)
       // c=a[i]/2+1;
       // else
           // c=a[i]/2;
      //cou+=c;
  }
  if(c%2==0) // because if both have odd left then a+b/2
    cou+=c/2; //otherwise both have a+b/2+1
  else
    cou+=(c/2)+1;

    cout<<cou<<endl;
    return 0;
}
