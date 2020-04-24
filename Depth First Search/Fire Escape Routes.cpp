/*
  Problem Link: https://www.codechef.com/problems/FIRESC
*/

#include<bits/stdc++.h>
#define		fast			ios::sync_with_stdio(false);cin.tie(0);cout.tie(NULL);
#define		rep(i,n)		for(int i = 1; i<=n; i++)
#define		all(p)			p.begin(),p.end()
#define		mem(ar,val)		memset(ar, val, sizeof(ar))
#define		sz(c)			(int)c.size()
#define		pb(x)			push_back(x)
#define		mkp(x,y)		make_pair(x,y)
#define		ff			first
#define		ss			second
#define 	pf 			printf
#define 	sf 			scanf
#define		ll			long long
#define		pii         	pair<int, int>
#define		pll         	pair<long long int, long long int>
#define		nl			"\n"
#define		FI			freopen("input.txt", "r", stdin);
#define 	FO			freopen("output.txt", "w", stdout);
using namespace std;
const int INF = 0x7f7f7f7f;
const int M = 1e9 + 7;
const int N = 1e5+7;
vector<int> adj[N];
bool vis[N];
int cnt = 0;
void dfs(int n)
{
	cnt++;
	vis[n] = true;
	for(int child : adj[n])
	{
		if(!vis[child])
			dfs(child);
	}
}
int main()
{
	fast
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		for(int i = 1; i<=n; i++)
		{
			adj[i].clear();
			vis[i] = false;
		}
		for(int i = 0; i<m; i++)
		{
			int a, b;
			cin>>a>>b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		int fe = 0;
		ll cap = 1;
		for(int i = 1; i<=n; i++)
		{
			if(!vis[i])
			{
				cnt = 0;
				fe++;
				dfs(i);
				cap = (cap * cnt)%M;
			}
		}
		cout<<fe<<" "<<cap<<nl;
	}
    return 0;
}

