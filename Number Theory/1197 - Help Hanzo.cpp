///Problem Link: http://lightoj.com/volume_showproblem.php?problem=1197
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int mx = 1000005;
vector<int> prime;
bool vis[mx];
int casino = 0;
void sieve()
{
	int x = sqrt(mx);
	for(int i = 3; i <= x; i += 2)
	{
		if(vis[i] == 0)
		{
			for(int j = i*i; j<mx; j += 2*i)
				vis[j] = 1;
		}
	}
	prime.pb(2);
	for(int i = 3; i<mx; i += 2)
		if(vis[i] == 0)
			prime.pb(i);
}
int segmentedSieve(ll a, ll b)
{
	if(b < 2) return 0;
	if(a < 2) a = 2;
	ll x = sqrt(b) + 1;
	memset(vis,0,sizeof(vis));
	for(ll i = 0; i < prime.size() && prime[i] <= x; i++)
	{
		ll j = prime[i] * prime[i];
		if(j < a) // If j is smaller than a, then shift it inside of segment [a,b]
			j = ((a + prime[i] - 1)/prime[i]) * prime[i];
			
		while(j <= b)
		{
			vis[j-a] = 1;
			j += prime[i];	
		}	
		
	}
	int cnt = 0;
	for(ll i = a; i <= b; i++)
		if(vis[i-a] == 0) cnt++;
	return cnt;
}
void solve()
{
	ll a, b;
	scanf("%lld %lld", &a, &b);
	int ans = segmentedSieve(a,b);
	printf("Case %d: %d\n", ++casino, ans);
}
int main()
{
	sieve();
	int t;
	scanf("%d",&t);
	while(t--)
	    solve();

	return 0;
}


