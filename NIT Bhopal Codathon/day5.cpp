#include<bits/stdc++.h>

#define M 1000000000000000000
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define s(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define p(a) printf("%d\n",a)
#define pl(a) printf("%lld\n",a)
#define mem(a,b) memset(a,b,sizeof(a))

using namespace std;
typedef long long ll;
map<ll,ll> mpp;

bool flag = false;

ll power(ll a, ll b)
{
	if(b==0) return 1;
	ll ans = power(a,b/2);
	ll B = (ans*ans);
	if((ans!=0) && ((B/ans)!=ans)) flag = true;
	if(b&1)
	{
		ll C = (B*a);
		if((a!=0) && ((C/a)!=B)) flag = true;
		B = C;
	}
	return B;
}

bool pr[1000002];
vector<ll> vc;
void markMult(ll num)
{
	for(ll i=num*num;i<1000002;i+=num)
	{
		 pr[i]=false;
	}
}

void sieve()
{
	pr[1]=pr[0]=false;
	markMult(2);
	vc.push_back(2);
	for(ll i=3;i*i<1000002;i+=2)
	{
		if(pr[i])
			markMult(i);
	}
	for(ll i=3;i<1000002;i+=2)
		if(pr[i]) vc.push_back(i);
}
ll divisor(ll num)
{
	int i=0; ll cnt; ll ans=1;
	while((vc[i]*vc[i])<=num)
	{
		cnt = 0;
		if(num%vc[i]==0)
		{
			while(num%vc[i]==0)
			{
				num/=vc[i];
				cnt++;
			}
		}
		ans*=(cnt+1);
		i++;
	}
	if(num>1) ans*=2;
	return ans;
}
int main()
{
    //cout<<power(10000,4)<<endl;
	memset(pr,true,sizeof(pr));
	sieve();
	ll i=1;
	while(true)
	{
		flag = false;
		ll div = divisor(i);
		ll po = power(i,div);

		if(mpp.count(po)==0 && !flag)
			mpp[po] = i;
		flag = false;
		if(div==2)
		{
			po = power(i,6);
			//if(i*i>900000) cout<<i<<endl;
			if(mpp.count(po)==0 && !flag)
				mpp[po] = i*i;
		}
		i++;
		if(i>100000) break;
	}

	int tc;
	s(tc);
	while(tc--)
	{
		ll N;
		sl(N);
		if(mpp.count(N)!=0) pl(mpp[N]);
		else
		{
			ll root = sqrt(N);
			if((root*root)==N)
			{
				ll di = divisor(root);
				if(di==2)
					pl(root);
				else printf("-1\n");
			}
			else
				printf("-1\n");
		}
	}
	return 0;
}
