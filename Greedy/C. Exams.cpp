// Problem Link: https://codeforces.com/problemset/problem/479/C
//Difficulty: 1400
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int comp(pair<int, int> a, pair<int, int> b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first < b.first;
}
void solve()
{
	int n, a, b;
	cin>>n;
	vector<pair<int, int> > ar;
	for(int i = 0; i<n; i++)
	{
		cin>>a>>b;
		ar.push_back({a, b});
	}
	sort(ar.begin(), ar.end(), comp);
	int ans = 0;
	for(int i = 0; i<n; i++)
	{
		if(ar[i].second >= ans)
			ans = ar[i].second;
		else
			ans = ar[i].first;
	}
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


