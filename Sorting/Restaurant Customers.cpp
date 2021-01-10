//Problem Link: https://cses.fi/problemset/task/1619
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
void solve()
{
	int n, a, b;
	cin>>n;
	vector<pair<int, int> >ar;
	for(int i = 0; i<n; i++)
	{
		cin>>a>>b;
		ar.pb({a, 1});
		ar.pb({b, -1});
	}
	sort(ar.begin(), ar.end());
	int ans = 0, sum = 0;
	
	for(int i = 0; i<sz(ar); i++)
	{
		sum += ar[i].second;
		ans = max(ans, sum);
	}
	cout<<ans<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

//	int t;
//	cin>>t;
//	while(t--)
	    solve();

	return 0;
}


