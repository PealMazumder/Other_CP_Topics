//Problem Link: https://codeforces.com/contest/1443/problem/C
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int comp(pair<int, int> a, pair<int, int> b)
{
	return (a.first > b.first);
}
void solve()
{
	int n;
	cin>>n;
	vector<pair<int, int> > v;
	int a[n], b;
	for(int i = 0; i<n; i++)
	{
		cin>>a[i];
	}
	for(int i = 0; i<n; i++)
	{
		cin>>b;
		v.pb({a[i], b});
	}
	sort(v.begin(), v.end(), comp);
	int ans = 0, cnt = 0;
	for(auto x: v)
	{
		if(x.first > (x.second+cnt))
		{
			ans = max(x.second + cnt, ans);
			cnt += x.second;
		}
		else 
		{
			ans = max(x.first, ans);
			cout<<ans<<nl;
			return;
		}
	}
	cout<<ans<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	    solve();

	return 0;
}


