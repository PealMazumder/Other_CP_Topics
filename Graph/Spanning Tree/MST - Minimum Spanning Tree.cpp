//Problem Link: https://www.spoj.com/problems/MST/
#include<bits/stdc++.h>
#define	ll	long long
#define	pll	pair<ll, ll>
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const ll N = 10002;
vector<pair<ll, ll> >adj[N];
bool vis[N];
ll prim(ll x)
{
	ll minCost = 0;
	pll p;
	priority_queue<pll, vector<pll>, greater<pll> > q;
	q.push({0, x});
	while(!q.empty())
	{
		p = q.top();
		q.pop();
		x = p.second;
		if(vis[x] == false)
		{
			minCost += p.first;
			vis[x] = true;
			for(ll i = 0; i<adj[x].size(); i++)
				if(vis[adj[x][i].second] == false)
					q.push(adj[x][i]);
		}
	}
	return minCost;
}
void solve()
{
	ll n, m, i, j, k, minCost;
	cin>>n>>m;
	while(m--)
	{
		cin>>i>>j>>k;
		adj[i].push_back({k, j});
		adj[j].push_back({k, i});
	}
	minCost = prim(i);
	cout<<minCost<<nl;
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


