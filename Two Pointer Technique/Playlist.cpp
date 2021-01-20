//Problem Link: https://cses.fi/problemset/task/1141
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;

void solve()
{
	ll n;
	cin>>n;
	ll ar[n];
	for(ll i = 0; i<n; i++)
		cin>>ar[i];
	map<ll, bool> mp;
	ll l = 0, r = 0, mx = 0;
	while(r < n)
	{
		if(mp[ar[r]] != 0)
		{
			mx = max(mx, r-l);
			while(l<r)
			{
				if(ar[l] == ar[r])
				{
					l++;
					break;
				}
				else
					mp[ar[l]] = 0;
				l++;
			}
		}
		else
		{
			mp[ar[r]] = 1;
		}
		r++;
	}
	mx = max(mx, r-l);
	cout<<mx<<nl;
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


