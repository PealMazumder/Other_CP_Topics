///Problem Link: https://www.codechef.com/LTIME94B/problems/LUNCHTIM/
#include<bits/stdc++.h>
#define		nl				"\n"
#define		sz(c)			(int)c.size()
#define		pb				push_back
#define		ff				first
#define		ss				second
#define		ll				long long
#define		all(p)			p.begin(),p.end()
using namespace std;
void solve()
{
	ll n;
	cin>>n;
	ll ar[n], x;
	
	ll ans[n] = {0};
	stack<pair<ll, ll>> st;
	map<ll, ll> mp;
	for(ll i = 0; i<n; i++)
	{
		cin>>x;
		if(st.empty() || st.top().ff >= x)
			st.push({x, i}), mp[x]++;
		else
		{
			set<ll> stt;
			while(!st.empty() && st.top().ff < x)
			{
				ans[st.top().ss] = mp[st.top().ff]-1;
				stt.insert(st.top().ff);
				st.pop();
			}
			st.push({x, i});
			mp[x]++;
			for(auto xx: stt)
				mp[xx] = 0;
		}
	}
	while(!st.empty())
	{
		ans[st.top().ss] = mp[st.top().ff]-1;
		st.pop();
	}
	for(ll i = 0; i<n; i++)
		cout<<ans[i]<<" ";
	cout<<nl;
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
