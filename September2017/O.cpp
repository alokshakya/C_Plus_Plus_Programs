#include<iostream>
#define boost {ios_base::sync_with_stdio(false); cin.tie(NULL);}
using namespace std;
int main()
{
    boost;
    int n,a,i;
    cin>>n;
    string ar[n+1];
    string s;

    for(i=1;i<=n;++i)
    {
        cin>>a;
        cin>>ar[a];
    }

    int co=0;

    for(i=0;i<n;++i)
    {
        cin>>a;
        cin>>s;
        int cha[26];int cha2[26];

        for(int j=0;j<26;j++)
        {
            cha[j]=cha2[j]=0;
        }

        int le=s.size();
        for(int j=0;j<le;++j)
        {
            cha[s[j] - 'a']++;
        }

        le=ar[a].size();
        for(int j=0;j<le;++j)
        {
            cha2[ar[a][j] - 'a']++;
        }

        for(int j=0;j<26;j++)
        {
            if(cha[j]==cha2[j]) continue;
            co++;
            break;
        }

    }
    cout<<co<<endl;
    return 0;
}
