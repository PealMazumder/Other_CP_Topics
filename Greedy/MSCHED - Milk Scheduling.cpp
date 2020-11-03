//Problem Link: https://www.spoj.com/problems/MSCHED/
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
	int g, d, n;
	cin>>n;
	vector<pair<int, int> > v;
	while(n--)
	{
		cin>>g>>d;
		v.pb({g, d});
	}
	sort(v.begin(), v.end(), comp);
	
	bool vis[10000] = {false};
	ll ans = 0;
	for(auto x : v)
	{
		for(int i = x.second; i>0; i--)
		{
			if(vis[i] == 0)
			{
				ans += x.first;
				vis[i] = true;
				break;
			}
		}
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


