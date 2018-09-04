#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,n;
    cin>>n;
    int ar[n];
    for(i=0;i<n;i++)
        cin>>ar[i];
    set<int> st;
    set<int>::iterator it;
    set<int>::iterator it2;
    for(i=0;i<n;i++)
    {
        st.insert(ar[i]);
        it=st.find(ar[i]);
        it++;
        if(it!=st.end())
        {
            st.erase(it);
        }
         for(it2=st.begin();it2!=st.end();it2++)
        cout<<*it2<< " ";
    cout<<endl;
    }
    for(it=st.begin();it!=st.end();it++)
        cout<<*it<< " ";
    cout<<endl;
    cout<<st.size()<<endl;
    return 0;
}
