/*
  Problem Link: https://codeforces.com/contest/727/problem/A
*/

#include<bits/stdc++.h>
#define	fast						ios::sync_with_stdio(false);cin.tie(0);cout.tie(NULL);
#define pb(x)					push_back(x)
#define ll						long long
#define nl						"\n"
#define sz(c)						(int)c.size()
using namespace std;
ll a,b;
map<ll , ll> mp;
void print(ll x)
{
	vector<ll> v;
	while(true)
	{
		v.push_back(x);
		x = mp[x];
		if(x == 0) break;
	}
	cout<<"YES\n";
	cout<<sz(v)<<nl;
	for(int i = sz(v)-1; i>=0; i--)
		cout<<v[i]<<" ";
	cout<<nl;
}
void bfs(int n)
{
	queue <ll> q;
	q.push(n);
	mp[n] = 0;
	while(!q.empty())
	{
		ll v = q.front();
		ll x = 2*v;
		ll y = 10*v + 1;
		mp[x] = v;
		mp[y] = v;
		q.pop();
		if(x == b)
		{
			print(x);
			return;
		}
		else if(y == b)
		{
			print(y);
			return;
		}
		
		if(x < b) q.push(x);
		if(y<b) q.push(y);	
			
		
	}
	cout<<"NO\n";
}
int main()
{
	fast
	cin>>a>>b;
	bfs(a);
    return 0;
}


