//Problem Link: https://codeforces.com/contest/1462/problem/D
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
vector<int> Divisors(int n, int len)
{
	vector<int> div;
	div.push_back(1);
	if(n < len)
		div.push_back(n);
	for(int i = 2; i*i<=n; i++)
	{
		if(!(n%i))
		{
			if(i < len)
				div.push_back(i);
			if(i * i != n && (n/i) < len)
				div.push_back(n/i);
		}
	}
	return div;
}

void solve()
{
	ll n;
	cin>>n;
	int ar[n];
	ll sum = 0;
	for(int i = 0; i<n; i++)
	{
		cin>>ar[i];
		sum += ar[i];
	}
	vector<int> d = Divisors(sum, n);
	d.push_back(n);
	for(int i = sz(d)-1; i>=0; i--)
	{
		int s = 0, need = sum/d[i], ans = 0;
		bool ck = false;
		for(int j = 0; j<n; j++)
		{
			if(s != 0) ans++;
			s += ar[j];
			if(s == need)
				s = 0;
			else if(s > need)
			{
				ck = true;
				break;
			}
		}
		if(s == 0 && ck == false)
		{
			cout<<ans<<nl;
			return;
		}
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	    solve();

	return 0;
}


