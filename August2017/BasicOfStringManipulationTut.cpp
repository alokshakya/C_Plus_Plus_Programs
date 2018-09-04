#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;string s;
        cin>>s>>n>>m;
        int l=s.length();
        char ch[l+1];
        int i=0;
        for(i=0;i<l;i++)
            ch[i]=s[i];
        sort(ch+n,ch+m+1,greater<char>());
        for(i=0;i<l;i++)
            cout<<ch[i];
        cout<<endl;
    }
    return 0;
}
