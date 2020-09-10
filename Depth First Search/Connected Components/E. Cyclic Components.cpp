//Problem link: https://codeforces.com/contest/977/problem/E
#include<bits/stdc++.h>
#define pb(x)						push_back(x)
using namespace std;
const int N = 2*1e5 + 1;
vector<vector<int> > adj;
vector<bool> vis;
bool ck = true;
void dfs(int v)
{
	vis[v] = true;
	if(adj[v].size() != 2) ck = false;
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
			dfs(i);
			if(ck == true)
				cnt++;
			ck = true;
		}
	}
	return cnt;
}
int main()
{
	int n, m;
	scanf("%d%d",&n,&m);
	adj.assign(n+1,vector<int>());
	vis.assign(n+1,false);
	for(int i = 0; i<m; i++)
	{
		int u, v;
		scanf("%d%d",&u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}	
	int ans = connectedComponents(n);
	printf("%d\n",ans);
	
    return 0;
}
