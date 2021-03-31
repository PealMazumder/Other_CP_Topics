//Problem Link: https://codeforces.com/contest/706/problem/B
// Without Buildin function: https://codeforces.com/contest/706/submission/48943652
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define sz(x) (int)x.size()
#define	all(p) p.begin(),p.end()

using namespace std;
void solve()
{
	ll n, m, k, i, j;
	cin>>n;
	vector<ll> ar(n);
	for(i = 0; i<n; i++)
		cin>>ar[i];
	sort(all(ar));
	ll q;
	cin>>q;
	while(q--)
	{
		cin>>m;
		auto it = upper_bound(all(ar), m);
		cout<< it - ar.begin()<<nl;
	}
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
//	ll t;
//	cin>>t;
//	while(t--)
		solve();
	return 0;
}
