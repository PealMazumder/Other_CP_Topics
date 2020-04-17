/*
  Problem Link: https://codeforces.com/contest/893/problem/C
*/
#include<bits/stdc++.h>
#define pb(x)					push_back(x)
#define ll						long long
#define nl						"\n"
using namespace std;
const int N = 1e5 + 5;
vector<int> adj[N];
vector<bool> vis(N);
int cost[N];
int mn = INT_MAX;
void dfs(int v)
{
	vis[v] = true;
	if(cost[v]<mn) mn = cost[v];
//	printf("%d ",v);
	for(int i = 0; i<adj[v].size(); i++)
	{
		int child = adj[v][i];
		if(!vis[child])
		{
			dfs(child);
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1; i<=n; i++)
	{
		scanf("%d",&cost[i]);
	}
	for(int i = 0; i<m; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	ll ans = 0;
	for(int i = 1; i<=n; i++)
	{
		if(!vis[i])
		{
			dfs(i);
			ans += mn;
			mn = INT_MAX;
		}
	}
	printf("%lld\n",ans);
    return 0;
}


