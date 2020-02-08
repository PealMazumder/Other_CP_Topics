#include<bits/stdc++.h>
#define pb(x)					push_back(x)
#define ll						long long
#define nl						"\n"
using namespace std;
const int N = 100000;
vector<int> adj[N];
vector<bool> vis(N);

void dfs(int v)
{
	vis[v] = true;
	printf("%d ",v);
	for(int i = 0; i<adj[v].size(); i++)
	{
		int child = adj[v][i];
		if(!vis[child])
			dfs(child);
	}
}
int main()
{
	int node,edge;
	scanf("%d%d",&node,&edge);
//    adj.assign(n,vector<int>());
//    vis.assign(n,false);
	for(int i = 0; i<edge; i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	dfs(1);
    return 0;
}

