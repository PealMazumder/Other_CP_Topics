/*
  Problem Link: https://codeforces.com/contest/24/problem/A
*/

#include<bits/stdc++.h>
#define pb(x)					push_back(x)
#define ll						long long
#define nl						"\n"
using namespace std;
const int N = 107;
vector<int> adj[N];
vector<bool> vis(N);
map<pair<int, int>, int> mp; // Instead of map we can use 2d array (like int cost[N][N])
int sum = 0;
bool ck = false;
void dfs(int v)
{
	vis[v] = true;
	for(int i = 0; i<adj[v].size(); i++)
	{
		int child = adj[v][i];
		if(!vis[child])
		{
			if(mp[{v,child}] == 0)
				sum += mp[{child,v}];
			dfs(child);
		}
	}
	
}
int main()
{
	int n;
	scanf("%d",&n);
	int tcost = 0;
	for(int i = 0; i<n; i++)
	{
		int u,v,c;
		scanf("%d%d%d",&u,&v,&c);
		adj[u].pb(v);
		adj[v].pb(u);
		mp[{u,v}] = c; // cost[u][v] = c
		mp[{v,u}] = 0; // cost[u][v] = 0
		tcost += c;
	}
	dfs(1);
	int tm = adj[1][1];
	
	if(mp[{tm,1}] == 0)
		sum += mp[{1,tm}];
		
	int ans = min(sum,tcost - sum);
	
	cout<<ans<<nl;
    return 0;
}


