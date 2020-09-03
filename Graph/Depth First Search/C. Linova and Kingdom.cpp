/*
  Problem Link: https://codeforces.com/contest/1337/problem/C
*/

#include<bits/stdc++.h>
#define pb(x)					push_back(x)
#define sz(c)						(int)c.size()
#define ll						long long
#define nl						"\n"
#define pii						pair<int, int>
using namespace std;
const int N = 2e5+5;
vector<int> adj[N];
vector<bool> vis(N);
int dis[N], chld[N];
priority_queue <int> pq;
int dfs(int n, int d)
{
	vis[n] = true;
	dis[n] = d;
	int cnt = 1;
	for(int u : adj[n])
	{
		if(!vis[u])
		{
			int c =	dfs(u, d+1);
			cnt += c;
		}
	}
	pq.push(dis[n] - cnt);
	return chld[n] = cnt;
}
int main()
{
	int n, k;
	scanf("%d %d",&n,&k);
	for(int i = 0; i<n-1; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1,1);
	ll ans = 0;
	int cnt = 1;
	while(!pq.empty())
	{
		int tm = pq.top();
		pq.pop();
		if(cnt<=k)
			ans += tm;
		cnt++;
	}
	cout<<ans<<nl;
    return 0;
}
