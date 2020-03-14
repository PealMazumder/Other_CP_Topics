/*
Problem Link: https://www.spoj.com/problems/PT07Y/
*/
#include<bits/stdc++.h>
#define sz(c)						(int)c.size()
#define pb(x)						push_back(x)
#define ll						long long
#define nl						"\n"
using namespace std;
const int INF = 0x7f7f7f7f;
vector<int> adj[10001];
bool vis[10000];
void dfs(int n)
{
	vis[n] = true;
	
	for(int child : adj[n])
	{
		if(!vis[child])
			dfs(child);
	}
}
void connectedC(int n)
{
	int cc = 0;
	for(int i = 1; i<=n; i++)
	{
		if(!vis[i])
		{
			cc++;
			if(cc>1)
			{
				cout<<"NO\n";
				return;	
			}
			dfs(i);
		}	
	}
	cout<<"YES\n";
}
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i = 0; i<m; i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);		
	}
	if(m != n-1)
		cout<<"NO\n";
	else
		connectedC(n);	
    return 0;
}


