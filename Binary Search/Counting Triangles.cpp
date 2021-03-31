//Problem Link: https://lightoj.com/problem/counting-triangles
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define sz(x) (int)x.size()
#define	all(p) p.begin(),p.end()

using namespace std;
int casino = 0;
void solve()
{
	ll n, m, k, i, j;
	cin>>n;
	vector<ll> ar(n);
	for(i = 0; i<n; i++)
		cin>>ar[i];
		
	sort(all(ar));
	ll ans = 0;
	for(i = 0; i<n-1; i++)
	{
		for(j = i+1; j<n; j++)
		{
			auto lwr = lower_bound(all(ar), ar[i] + ar[j]);
			lwr--;
			if(lwr != ar.end())
			{
				ll idx = lwr - ar.begin();
				if(idx > j)
					ans += (idx - j);
			}
		}
	}
	cout<<"Case "<<++casino<<": "<<ans<<nl;
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
