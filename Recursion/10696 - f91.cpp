//Problem Link: https://onlinejudge.org/external/106/10696.pdf
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define sz(x) (int)x.size()
#define	all(p) p.begin(),p.end()

using namespace std;
const int N = 1e6+1;
ll dp[N];
ll f91(ll n)
{
	if(n>100) return dp[n] = n - 10;
	if(dp[n] != -1) return dp[n];
	return dp[n] = f91(f91(n+11));
}
void solve()
{
	ll n, m, k, i, j;
	memset(dp, -1, sizeof dp);
	while(scanf("%lld", &n) && n)
	{
		ll ans = f91(n);
		printf("f91(%lld) = %lld\n",n, ans);
	}
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(NULL);
//	ll t;
//	cin>>t;
//	while(t--)
		solve();
	return 0;
}

