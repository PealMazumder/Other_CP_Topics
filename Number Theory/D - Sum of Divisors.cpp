//Problem: https://atcoder.jp/contests/abc172/tasks/abc172_d
#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
using namespace std;
void solve()
{
	int n;
	scanf("%d",&n);
	
	vector<int> div(n+1, 0);
	for(int i = 1; i<=n; i++)
	{
		for(int j = 0; j<=n; j += i)
			div[j]++;
	}
	ll ans = 0;
	for(ll i = 1; i<=n; i++)
		ans += (i * (ll)div[i]);
	
	printf("%lld\n",ans);
}
int main()
{
	solve();
	return 0;
}
