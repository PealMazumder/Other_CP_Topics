#include<bits/stdc++.h>
#define ll long long
#define 	FO			freopen("output.txt", "w", stdout);
using namespace std;
int casino = 0;
const ll N = 1e6 + 1;
vector<ll> prime;
bool vis[N];
void sieve()
{
	for(ll i = 3; i*i<=N; i+=2)
	{
		if(!vis[i])
		{
			for(ll j = i*i; j<=N; j += 2*i)
				vis[j] = true;
		}
	}
	prime.push_back(2LL);
	for(ll i = 3; i<N; i += 2)
		if(!vis[i]) prime.push_back(i);
}
ll NOD(ll n)
{
	ll ret = 1;
	ll root = sqrt(n);
	for(ll i = 0;i<prime.size() && prime[i]<=root; i++)
	{
		if(n%prime[i] == 0)
		{
			int cnt = 1;
			while(n%prime[i] == 0)
			{
				cnt++;
				n/=prime[i];
			}
			ret *= cnt;
			root = sqrt(n);
		}
	}
	if(n>1LL)
		ret *= 2;
	return ret;
}
void solve()
{
	ll n;
	scanf("%lld",&n);
	ll ans = NOD(n);
	printf("Case %d: ",++casino);
	printf("%lld\n",--ans);
}

int main()
{
	//FO
	sieve();
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}
