//Problem Link: https://www.spoj.com/problems/AGGRCOW/
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define sz(x) (int)x.size()
#define	all(p) p.begin(),p.end()

using namespace std;
void solve()
{
	ll n, m, k, c, i, j;
	cin>>n>>c;
	vector<ll> v;
	for(i = 0; i<n; i++)
		cin>>j, v.push_back(j);
	sort(all(v));
	ll l = v[0], r = v.back() - v[0];
	ll ans = 1;
	while(l <= r)
	{
		ll mid = l + (r-l)/2;
		ll pre = v[0], cc = c-1;
		for(i = 1; i<sz(v); i++)
		{
			if(v[i] - pre >= mid)
				cc--, pre = v[i];
			if(cc <= 0) break;
		}
		if(cc <= 0)
			l = mid+1, ans = max(ans, mid);
		else r = mid-1;
	}
	cout<<ans<<nl;
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}

