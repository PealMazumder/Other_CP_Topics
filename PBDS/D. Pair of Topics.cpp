//Problem Link: https://codeforces.com/contest/1324/problem/D
#include<bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define nl "\n"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ll n, ans, i, j;
ll a[200001],b[200001];
void solve()
{
	cin>>n;
	for(i = 0; i<n; i++)
		cin>>a[i];
	for(i = 0; i<n; i++)
		cin>>b[i];
	ans = 0;
	oset<pair<ll, ll> > s;
	for(i = 0; i<n; i++)
	{
		ans += s.order_of_key({a[i] - b[i], 0});
		s.insert({b[i] - a[i], i});
	}
	cout<<ans<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	
	solve();

	return 0;
}

