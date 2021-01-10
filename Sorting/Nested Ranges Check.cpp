#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b)
{
	if(a.first == b.first)
		return a.second > b.second;
	return a.first < b.first;
}
bool comp1(pair<int, int> a, pair<int, int> b)
{
	if(a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}
void solve()
{
	int n, tm;
	cin>>n;
	map<pair<int, int>, int> idx;
	vector<pair<int, int> > ar(n);
	for(int i = 0; i < n; i++)
	{
		cin>>ar[i].first>>ar[i].second;
		idx[{ar[i].first, ar[i].second}] = i;
	}
	sort(ar.begin(),ar.end(), comp);
	vector<int> mn(n, 0);
	tm = INT_MAX;
	for(int i = n-1; i >= 0; i--)
	{
		mn[i] = min(ar[i].second, tm);
		tm = mn[i];
	}
	vector<int> ans1(n, 0), ans2(n, 0);
	for(int i = 0; i<n-1; i++)
	{
		if(ar[i].second >= mn[i+1])
			ans1[idx[{ar[i].first, ar[i].second}] ]= 1;
	}
 
	sort(ar.begin(),ar.end(), comp1);
	vector<int> mx(n, 0);
	tm = INT_MIN;
	for(int i = n-1; i >= 0; i--)
	{
		mx[i] = max(ar[i].second, tm);
		tm = mx[i];
	}
	for(int i = 0; i<n-1; i++)
	{
		if(ar[i].second <= mx[i+1])
			ans2[idx[{ar[i].first, ar[i].second}]]= 1;
	}
	for(int i = 0; i<n; i++)
		cout<<ans1[i]<<" ";
	cout<<nl;
	for(int i = 0; i<n; i++)
		cout<<ans2[i]<<" ";
	cout<<nl;
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