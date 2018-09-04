#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
#define MOD 1000000007
#define MAX 20000002

#define gc getchar_unlocked
void scanll(long long &x)
{
    register long long c = gc();
    x = 0;
    long long neg = 0;
    for(;((c<48 || c>57) && c != '-');c = gc());
    if(c=='-') {neg=1;c=gc();}
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
    if(neg) x=-x;
}

ll _sieve_size;        // 10^7 should be enough for most cases
bitset<1000010> bs;  // compact STL for Sieve, better than vector<bool>!
// vi primes;        // compact list of primes in form of vector<int>

void sieve(ll upperbound)
{
  _sieve_size = upperbound + 1;
  bs.set();
  bs[0] = bs[1] = 0;
  // create list of primes in [0..upperbound]
  // add 1 to include upperbound
  // set all bits to 1
  // except index 0 and 1
  for (ll i = 2; i <= _sieve_size; i++)
  {
    if (bs[i])
    {
      // cross out multiples of i starting from i * i!
      for (ll j = i * i; j <= _sieve_size; j += i) bs[j] = 0;
      // primes.push_back((int)i);
    }
  }
}



void solve()
{
  ll n;
  scanll(n);
  ll x = sqrt(n);
  if(n<2 or x*x!=n)
  {
    cout<<"No\n";
    return;
  }
  // cout<<x<<endl;
  if(bs[x]) cout<<"Yes\n";
  else cout<<"No\n";
}

int main()
{
  sieve(1000002);
  ll t=1;
  scanll(t);
  while(t--)
  {

  }
}
