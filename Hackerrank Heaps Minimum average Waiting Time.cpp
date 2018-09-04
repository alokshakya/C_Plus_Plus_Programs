#include<iostream>
#include<queue>
#include<map>
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
        return n1.s>n2.s;
    }
};
int main()
{
    priority_queue<p,vector <p>, compareV> Q;
    map<int,int> mymap;
    int n,t,l,i,su=0;
    cin>>n;
   /* for(i=0;i<=100000000;++i)
    {
        ar[i]=0;
    }*/
    for(i=1;i<=n;++i)
    {
        cin>>t>>l;
        mymap[t]=l;
    }
    int T=0;
    Q.push(mp(T,mymap[T])); T++;

    while(!Q.empty())
    {
        cout<<" t : "<<Q.top().f<<" cook time :"<<Q.top().s<<endl;
        su+=((Q.top().s+su)-Q.top().f); Q.pop();
        cout<<"su "<<su<<endl;
        cout<<"Queue size "<<Q.size()<<endl;
        int j=T;
        cout<<" j = "<<j<<endl;

        while(j<su && j<n)
        {
            Q.push(mp(j,mymap[j]));
            cout<<" inside while j = "<<j<<endl;
            j++;
        }
        cout<<" T = "<<T<<endl;
        T=su;

    }
    cout<<su/n<<endl;
    return 0;
}
