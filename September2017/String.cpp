#include<bits/stdc++.h>
using namespace std;
int ar[26];
void ini()
{
    for(int j=0;j<26;j++)
    {
        ar[j]=0;
    }
}
int findMax(string s)
{
    ini();
    int ma=0;
    int cnt=0;
    int l=s.size();
    for(int i=0;i<l;i++)
    {

        if(ar[s[i]-'a']==0)
        {
           cnt++;
           ar[s[i]-'a']++;
           if(i==(l-1) )
          {
            //cout<<endl<<s[i]<<" "<<cnt<<" : "<<" ma : "<<ma;
            if(ma<=cnt)
            {
                ma=cnt;
            }

          }
        }
        else
        {
            //cout<<s[i]<<" "<<cnt<<" : ";
            if(i==(l-1))
            {
               cnt--;
            }
            if(ma<=cnt)
            {
                ma=cnt;
            }
            cnt=1;
            ini();

        }


    }
    return ma;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        int out=findMax(s);
        cout<<out<<endl;
    }

    return 0;
}
