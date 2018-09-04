#include<bits/stdc++.h>
#define inf 1e18
#define ll long long
using namespace std;
ll a,b,n,l;
ll gcd(ll x,ll y)
{
	if(y==0)return x;
	else return gcd(y,x%y);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cin>>n;
		ll low=min(a,b);//find minimum of two
		ll high=inf;
		ll ans;
		l=(a*b)/gcd(a,b);//calculated lcm of a,b
		//used binary search algorithm
		ll it=0;
		while(low<=high)
		{
			ll mid=(low+high)/2;
			ll val= mid/a + mid/b - mid/l;
			cout<<" mid in itr : "<<it<<" is : "<<mid<<" low: "<<low<<" high: "<<high<<" val: "<<val<<endl;
			if(val>=n)
			{
				ans=mid;
				high=mid-1;
			}
			else
				low=mid+1;
            it++;
		}
		cout<<ans<<"\n";
	}
}
