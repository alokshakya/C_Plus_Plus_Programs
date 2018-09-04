#include<iostream>
using namespace std;
int cnt[26];
int main()
{
  int c=0;
  string s;
  cin >> s;
  int n=s.size();
for (int i = 0; i < n; ++i) {
    cnt[s[i] - 'a']++;
  //  cout<<cnt[s[i]-'a']<<endl;
  }
  for(int j=0; j<26;++j)
  {
      if(cnt[j]>1)
      {
          c+=cnt[j]-1;
      }
  }
  cout<<c<<endl;
  return 0;
}
