/*
Problem Link: shorturl.at/adxJY
*/
#include<bits/stdc++.h>
#define pb(x)						push_back(x)
using namespace std;
const int INF = 0x7f7f7f7f;
vector<vector<int> > adj;
vector<bool> vis;
void dfs(int v)
{
	vis[v] = true;
	for(int i = 0; i<adj[v].size(); i++)
	{
		int child = adj[v][i];
		if(!vis[child])
			dfs(child);
	}
}
int connectedComponents(int n)
{
	int cnt = 0;
	for(int i = 1; i<=n; i++)
	{
		if(!vis[i])
		{
			cnt++;
			dfs(i);
		}
	}
	return cnt;
}
int main()
{
	int n,e;
	scanf("%d%d",&n,&e);
	adj.assign(n+1,vector<int>());
	vis.assign(n+1,false);
	for(int i = 0;i<e;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}	
	int ans = connectedComponents(n);
	printf("%d\n",ans);
	
    return 0;
}


