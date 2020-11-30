///Problem Link: https://codeforces.com/contest/492/problem/C
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
ll comp(pair<int, int> a, pair<int, int>b)
{
	return a.second < b.second;
}
void solve()
{
	ll n, r, avg, a, b, sum = 0;
	cin>>n>>r>>avg;
	vector<pair<ll, ll> > ar;
	for(ll i = 0; i<n; i++)
	{
		cin>>a>>b;
		sum += a;
		ar.push_back({a, b});
	}
	
	ll av = sum/n, need;
	if(av >= avg)
	{
		cout<<"0\n";
		return;
	}
	need = avg*n - sum;
	sort(ar.begin(), ar.end(), comp);
	ll minEss = 0;
	for(auto xx : ar)
	{
		if(xx.first >= r) continue;
		ll tm = r - xx.first;
		if(tm >= need)
		{
			minEss += xx.second * need;
			break;
		}
		else
		{
			minEss += xx.second * tm;
			need -= tm;
		}
	}
	cout<<minEss<<nl;
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

