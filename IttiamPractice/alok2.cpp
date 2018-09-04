#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ar[26];
    int k,i,j;
    string s;
    cin>>s;
    int n=s.size();
    cin>>k;
    for(i=0;i<26;i++)
        ar[i]=0;
    for(i=0;i<n;i++)
    {
        ar[ s[i]-'a' ]++;
         //cout<<"s[i]-a "<<s[i]-'a'<< "\t";
    }
    for(i=0;i<n;i++)
    {
        //char ch=s[i];
        if(ar[ s[i]-'a' ]>=k)
            cout<<s[i];
    }

    return 0;
}
