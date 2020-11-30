//Problem Link: https://codeforces.com/contest/580/problem/C
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int N = 100005;
vector<int> adj[N];
vector<bool> vis(N), cat(N);
vector<int>conseCat(N);
int n, m, a, b;
int bfs(int n)
{
	int cnt = 0;
	queue<int> q;
	vis[n] = true;
	q.push(n);
	if(cat[n])
		conseCat[n] = 1;
	while(!q.empty())
	{
		int v = q.front();
		q.pop();
		bool ck = false;
		for(int u : adj[v])
		{
			if(!vis[u])
			{
				ck = true;
				vis[u] = true;
				q.push(u);
				if(cat[u] == true)
					conseCat[u] += conseCat[v]+ 1;
				else if(conseCat[v] > m)
					conseCat[u] = conseCat[v];
				else
					conseCat[u] = 0;
			}
		}
		if(ck == false && conseCat[v] <= m)
			cnt++;
	}
	return cnt;
}
void solve()
{
	int c;
	cin>>n>>m;
	for(int i = 1; i<=n; i++)
	{
		cin>>c;
		if(c == 1)cat[i] = true;
		else cat[i] = false;
	}
	for(int i = 0; i<n-1; i++)
	{
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = bfs(1);
	cout<<ans<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

//	int t;
//	cin>>t;
//	while(t--)
	    solve();

	return 0;
}


