#include<bits/stdc++.h>
#define pb(x)						push_back(x)
using namespace std;
const int N =  10002;
vector<int> adj[N];
vector<bool> vis(N);
vector<int> dis(N);
int mx = 0,nd = 0;
void dfs(int v, int d)
{
	vis[v] = true;
	dis[v] = d;
	if(d>mx)
	{
		mx = d;
		nd = v;
	}
	for(int i = 0; i<adj[v].size(); i++)
	{
		int child = adj[v][i];
		if(!vis[child])
			dfs(child,d+1);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	
	int u,v;
	for(int i = 1; i<n; i++)
	{
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(u,0);
	vis.assign(N,false);
	dis.assign(N,0);
	dfs(nd, 0);
	
	printf("%d\n",mx);
    return 0;
}

