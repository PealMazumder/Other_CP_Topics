//Problem Link: https://codeforces.com/contest/1144/problem/F
#include<bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define nl "\n"
using namespace std;
int n, m, a, b;
const int N = 200005;
vector<int> adj[N];
vector<bool> vis(N),col(N);
vector<pair<int, int> > v;
bool dfs(int n, int c)
{
	vis[n] = true;
	col[n] = c;
	
	for(int child : adj[n])
	{
		if(vis[child] == false)
		{
			dfs(child, c^1);
		}
		else if(col[n] == col[child])
		{
			cout<<"NO\n";
			exit(0);
		}
	}
	return true;
}
void solve()
{
	cin>>n>>m;
	for(int i = 0; i<m; i++)
	{
		cin>>a>>b;
		v.push_back(make_pair(a, b));
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	dfs(1,1);
	cout<<"YES\n";
	for(auto x : v)
		cout<<col[x.first];
	cout<<nl;

}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	
    solve();

	return 0;
}

