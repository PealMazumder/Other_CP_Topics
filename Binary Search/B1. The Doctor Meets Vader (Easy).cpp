//Problem Link: https://codeforces.com/contest/1184/problem/B1
#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define nl "\n"
using namespace std;
const ll mx = 1000000009;
ll gold[100001];
void solve()
{
	ll s, b, a[100001],d, g, i;
	cin>>s>>b;
	for(i = 0;i<s; i++)
		cin>>a[i];
	vector<pair<ll, ll> > v;
	for(i = 0; i<b; i++)
	{
		cin>>d>>g;
		v.push_back({d,g});
	}
	sort(v.begin(), v.end());
	i = 0;
	gold[i] = v[i].second;
	for(i = 1; i<b; i++)
		gold[i] =gold[i-1] + v[i].second;
	for(i = 0; i<s; i++)
	{
		int pos = upper_bound(v.begin(), v.end(),make_pair(a[i], mx)) - v.begin();
		cout<<gold[pos-1]<<" ";
	}
	cout<<nl;
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	
	solve();

	return 0;
}

