#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t,i;
        string s;
       cin>>s;
        int l= s.length();
       // cout<<"length "<<l<<endl;
        char ch[l];
        for(i=0;i<l;i++)
        {
            if(i==0)
            {
                if(s[i]=='?' && s[i+1]=='b')
                    ch[i]='a';
               else if(s[i]=='?' && s[i+1]=='a')
                    ch[i]='b';
              else  if(s[i]!='?')
                    ch[i]=s[i];
            }
            else
            {
                if(s[i]=='?' && ch[i-1]=='a')
                    ch[i]='b';
               else if(s[i]=='?' && s[i+1]=='b')
                    ch[i]='a';
                    else if(s[i]=='?' && s[i+1]=='a')
                    ch[i]='b';
                    else if(s[i]=='?' && s[i+1]=='?' && ch[i-1]=='b')
                    ch[i]='a';
               else if(s[i]!='?')
                        ch[i]=s[i];

            }

        }
        for(i=0;i<l;i++)
            cout<<ch[i];
        cout<<endl;
        //cout<<"character array is :"<<ch<<endl;


    return 0;
}
