#include<iostream>
#include<queue>
#include<cmath>
#define p pair<int,int>
#define f first
#define s second
#define mp make_pair
using namespace std;
//long long ar[100000005];
class compareV
{
public:
    bool operator()(p n1,p n2)
    {
        if(n1.f==n2.f)
        return n1.s>n2.s;
        else
            return n1.f>n2.f;
    }
};
int main()
{
    priority_queue<p,vector <p>, compareV> Q;

    int n,h,i,a,b;
    cin>>n>>h;
    for(i=1;i<=n;++i)
    {
        cin>>a>>b;
        Q.push(mp(a,b));
    }
    int co=0;
    p z=Q.top();Q.pop();

    while(!Q.empty())
    {

        p x=Q.top();
        cout<<"Q.top of z "<<z.f<<"  "<<z.s<<endl;
cout<<"Q.top of x "<<x.f<<"  "<<x.s<<endl;
        //cout<<"age : "<<z.f<<" x axis :"<<z.s<<endl;
        if(z.s>0)
        {
            if(!(x.s<0 && abs(z.s-x.s)<=h))
            {
                Q.pop();
                x=Q.top();

            }
            if(x.s<0 && (abs(z.s-x.s)<=h))
            {
                co++;
                z=x;
                Q.pop();
            }

        }
        else
        {
            if(!(x.s>0 && (abs(z.s-x.s)<=h)))
            {
                Q.pop();
                x=Q.top();
            }
            if(x.s>0 && (abs(z.s-x.s)<=h))
            {
                co++;
                z=x;
                Q.pop();
            }
        }

    }
    cout<<"ans is "<<co<<endl;
    return 0;
}
