/*
  Problem Link: https://www.spoj.com/problems/BUGLIFE/
  Tutorials on :
*/

#include<bits/stdc++.h>
using namespace std;
const int N = 1000007;
vector<int> adj[N];
vector<bool> vis(N),col(N);
bool dfs(int n, int c)
{
	vis[n] = true;
	col[n] = c;
	
	for(int child : adj[n])
	{
		if(!vis[child])
		{
			if(dfs(child, c^1) == false)
				return false;
		}
		else
		{
			if(col[n] == col[child])
				return false;
		}
	}
	return true;
}
int main()
{
	int t,casino = 0;
	scanf("%d",&t);
	while(t--)
	{
		int n,e;
		scanf("%d%d",&n,&e);
		for(int i = 0; i<=n; i++)
		{
			adj[i].clear();
			vis[i] =  false;
			col[i] = false;
		}
		vector<int> u(e+1);
		for(int i = 0; i<e; i++)
		{
			int v;
			scanf("%d%d",&u[i],&v);
			adj[u[i]].push_back(v);
			adj[v].push_back(u[i]);
		}
		printf("Scenario #%d:\n",++casino);
		bool ck = true;
		for(int i = 0; i<e; i++)
		{
			if(!vis[u[i]])
			{
				ck = dfs(u[i],1);
				if(!ck)
					break;
			}
		}
		if(ck)
			printf("No suspicious bugs found!\n");
		else
			printf("Suspicious bugs found!\n");
	}
	return 0;
}
