//Problem Link: https://codeforces.com/contest/977/problem/D
#include<bits/stdc++.h>
#define ll long long
#define nl "\n"
#define sz(v) (int)v.size()
using namespace std;
ll n,cn, curr;
ll ar[101];
map<ll, ll> mp, p,lvl;
void printPath(ll a)
{
	if(p[a] != 0)
		printPath(p[a]);
	cout<<a<<" ";
	
}
bool bfs(ll a)
{
	p.clear();
	queue<ll> q;
	q.push(a);
	lvl[a] = 1;
	while(!q.empty())
	{
		curr = q.front();
		q.pop();
		if(curr % 3 == 0 && mp[curr/3] > 0)
		{
			p[curr/3] = curr;
			q.push(curr/3);
			lvl[curr/3] = lvl[curr]+1;
		}
		if(mp[curr * 2] > 0)
		{
			p[curr*2] = curr;
			q.push(curr * 2);
			lvl[curr * 2] = lvl[curr]+1;
		}
		if(lvl[curr] == n)
		{
			printPath(curr);
			cout<<"\n";
			return true;
		}
	}
	return false;
}
void solve()
{
	cin>>n;
	for(ll i = 0; i<n; i++)
	{
		cin>>ar[i];
		mp[ar[i]]++;
	}
	for(ll i = 0; i<n; i++)
	{
		bool ck = bfs(ar[i]);
		if(ck) break;
	}
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

