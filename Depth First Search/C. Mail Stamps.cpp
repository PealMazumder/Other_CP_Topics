/*
  Problem Link: https://codeforces.com/contest/29/problem/C
  Tutorials on Diameter of the Tree: 
  					https://www.youtube.com/watch?v=FQLPNQppBNs&list=PL2q4fbVm1Ik6DCzm9XZJbNwyHtHGclcEh&index=14
*/

#include<bits/stdc++.h>
#define pb(x)					push_back(x)
#define ll						long long
#define nl						"\n"
using namespace std;
const int N = 100000;
map<ll, vector<ll> > adj;
map<ll, bool> vis;
map<ll, ll> p;
ll mx = 0, nd = 0;
void dfs(ll v, ll d)
{
	vis[v] = true;
//	printf("%d ",v);
	if(d>mx)
	{
		mx = d;
		nd = v;
	}
	for(int i = 0; i<adj[v].size(); i++)
	{
		ll child = adj[v][i];
		if(!vis[child])
		{
			p[child] = v;
			dfs(child, d+1);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	ll u,v;
	for(int i = 0; i<n; i++)
	{
		scanf("%lld%lld",&u,&v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	p[u] = 0;
	dfs(u, 0);
	vis.clear();
	p.clear();
	mx = 0;
	dfs(nd, 0);
	while(true)
	{
		cout<<nd<<" ";
		nd = p[nd];
		if(nd == 0) break;
	}
    return 0;
}


