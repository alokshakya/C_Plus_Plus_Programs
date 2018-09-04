/*
If frequent operation is insertion and deletion and finding minimum and maximum
in a data structure use set instead of priority_queue it will be efficient that modified form of
priority_queue.
*/

#include<iostream>
#include<set>
#include<algorithm>
#include<functional>
using namespace std;
int main()
{
    int t,a,b;
    cin>>t;
    set<int> Q;
    set<int>::iterator it;
    while(t--)
        {
        cin>>a;
        if(a==1)
            {
            cin>>b;
                       Q.insert(b);
        }
        if(a==2)
            {
            cin>>b;
            Q.erase(b);

        }
        if(a==3)
        {
            cout<<*(Q.begin())<<endl;
        }


    }


return 0;
 }
