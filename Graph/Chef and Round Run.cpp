//Problem Link: https://www.codechef.com/problems/CHEFRRUN
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int mx = 1000005;
vector<int> g[mx], gr[mx];
bool vis[mx];
vector<int> order, scc;
void dfs1(int node)
{
	vis[node] = 1;
	for(int child : g[node])
		if(vis[child] == 0)
			dfs1(child);
	order.pb(node);
}
void dfs2(int node)
{
	vis[node] = 1;
	for(int child : gr[node])
		if(vis[child] == 0)
			dfs2(child);
	scc.pb(node);
}
void solve()
{
	int n, ans = 0;
	cin>>n;
	int ar[n];
	for(int i = 0; i<n; i++)
		g[i].clear(), gr[i].clear(),vis[i] = 0, cin>>ar[i];
	order.clear(); 
	
	for(int i = 0; i<n; i++)
	{
		int a = (i + ar[i] + 1) % n;
		g[i].pb(a);
		gr[a].pb(i);
	}
	for(int i = 0; i<n; i++)
		if(vis[i] == 0)
			dfs1(i);
	for(int i = 0; i<n; i++) vis[i] = 0;
	
	for(int i = sz(order) - 1; i>=0; i--)
	{
		if(vis[order[i]] == 0)
		{
			scc.clear();
			dfs2(order[i]);	
			if(sz(scc) == 1 && (scc[0] != g[scc[0]][0])) continue;
			
			ans += sz(scc);
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
