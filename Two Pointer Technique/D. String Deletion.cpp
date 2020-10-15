///Problem Link: http://codeforces.com/contest/1430/problem/D
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;

void solve()
{
	int n;
	string s;
	cin>>n>>s;
	vector<int> c;
	int cnt = 1;
	for(int i = 1; i<sz(s); i++)
	{
		if(s[i] == s[i-1])
			cnt++;
		else
		{
			c.pb(cnt);
			cnt = 1;
		}
	}
	c.pb(cnt);
	int l = 0,r = 0, ans = 0;
	while(r < sz(c))
	{
		if(c[r] > 1)
		{
			c[r] = c[r] - 1;
			if(r == l) r++;
			ans++, l++;
		}
		else r++;
	}
	
	ans += (sz(c) - l +1)/2;
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


