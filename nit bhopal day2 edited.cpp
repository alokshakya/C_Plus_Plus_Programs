#include<iostream>
using namespace std;
int alphabt[26];
int main()
{
    ios::sync_with_stdio(0);//uses just 64K without it uses 672K
  int n, q;
  string s;
  cin >> n >> q >> s;

  for (int i = 0; i < n; ++i) {
    alphabt[s[i] - 'A']++;
  }

  while (q--)
{
    int ty, x;
    char c;
    cin >> ty >> x;
    --x;

    if (ty == 1) {
      cin >> c;
      int old = s[x] - 'A';
      s[x] = c;
      alphabt[c - 'A']++;
      alphabt[old]--;
    }
    else
    {
      int tot = 0;
      for (int i = 0; i < 26; ++i)
    {
        tot += alphabt[i];
        if (tot > x)
        {
          cout << (char) (i + 'A') << endl;
          break;
        }
      }
    }
  }
  return (0);
}
