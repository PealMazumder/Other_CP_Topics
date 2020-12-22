//Problem Link: https://codeforces.com/contest/1465/problem/C
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
bool dfs(vector<ll> adj[], vector<bool> &vis, ll n, ll start)
{
	vis[n] = true;
	for(auto v : adj[n])
	{
		if(!vis[v])
			return dfs(adj, vis, v, start);
		else if(v == start)
		{
//			cout<<v<<" inside"<<nl;
			return true;
		}
	}
//	if(cnt == 0) vis[n] = false;
	return false;
}

void solve()
{
	ll n, m, a, b, i, ans = 0;
	cin>>n>>m;
	vector<ll> adj[n+1];
	vector<bool> vis(n+1, false);
	for(i = 0; i<m; i++)
	{
		cin>>a>>b;
		if(a != b)
		{
			ans++;
			adj[a].pb(b);
		}
		else vis[a] = true;
	}
	
	for(i = 1; i<=n; i++)
	{
		if(!vis[i] && dfs(adj, vis, i, i))
		{
			ans++;
//			cout<<i<<" i \n";
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


