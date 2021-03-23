//Problem Link: https://www.spoj.com/problems/SORT2D/en/
#include<bits/stdc++.h>
#define		nl				"\n"
#define		sz(c)			(int)c.size()
#define		pb				push_back
#define		f				first
#define		s				second
#define		ll				long long
using namespace std;
bool comp(pair<ll, ll>a, pair<ll, ll> b)
{
	if(a.f == b.f && a.s < b.s || a.f > b.f) return false;
	else return true;
}
void solve()
{
	ll n, i, j, x, y;
	cin>>n;
	vector<pair<ll, ll> > v;
	for(i = 0; i<n; i++)
		cin>>x>>y, v.pb({x, y});
	
	sort(v.begin(), v.end(), comp);
	for(auto xx : v)
		cout<<xx.f<<" "<<xx.s<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
