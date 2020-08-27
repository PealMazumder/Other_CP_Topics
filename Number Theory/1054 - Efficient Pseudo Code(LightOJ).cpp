#include<bits/stdc++.h>
#define	ll	long long
using namespace std;
const ll mod = 1000000007;
int casino = 0;
ll pow(ll b, ll p)
{
	ll res = 1;
	while(p)
	{
		if(p & 1)
			res = (res * b) % mod;
			
		p /= 2;
		b = (b * b) % mod;
	}
	return res;
}
ll SOD(ll n, ll m)
{
	ll res = 1;
	for(ll i = 2; i*i <= n; i++)
	{
		if(n % i == 0)
		{
			ll cnt = 0;
			while(n % i == 0)
			{
				cnt++;
				n /= i;
			}
			cnt *= m;
			cnt++;
			res  = (((res * (pow(i, cnt) - 1)) % mod) * pow(i-1,mod-2)) % mod;
		}
	}
	
	if(n > 1)
	{
		if(n % mod == 0)
			res = 1;
		else
			res = (((res * (pow(n, 1+m) - 1)) % mod) * pow(n-1, mod - 2)) % mod;
	}
	return res;
}

void solve()
{
	ll n, m;
	scanf("%lld %lld", &n, &m);
	ll ans = SOD(n,m);
	printf("Case %d: %lld\n", ++casino,ans);
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	    solve();

	return 0;
}

