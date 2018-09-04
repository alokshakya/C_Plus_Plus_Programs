#include <bits/stdc++.h>

using namespace std;

int cnt[26];

int main()
{
  ios::sync_with_stdio(0);
  int n, q;
  string s;
  cin >> n >> q >> s;

  for (int i = 0; i < n; ++i) {
    cnt[s[i] - 'A']++;
  }

  while (q--) {
    int ty, x;
    char c;
    cin >> ty >> x;
    --x;

    if (ty == 1) {
      cin >> c;
      int old = s[x] - 'A';
      s[x] = c;
      cnt[c - 'A']++;
      cnt[old]--;
    } else {
      int tot = 0, good = 0;
      for (int i = 0; i < 26; ++i) {
        tot += cnt[i];
        if (tot > x) {
          cout << (char) (i + 'A') << endl;
          good = 1;
          break;
        }
      }
      assert(good);
    }
  }
  return(0);
}
