///Problem Link: https://cses.fi/problemset/task/1629
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b)
{
	return (a.second < b.second);
}
void solve()
{
	int n;
	cin>>n;
	vector<pair<int, int> > ar(n);
	for(int i = 0; i<n; i++)
		cin>>ar[i].first>>ar[i].second;
	sort(ar.begin(), ar.end(), comp);
	int cnt = 0, temp = 0;
	for(int i = 0; i<n; i++)
	{
		if(ar[i].first >= temp)
			cnt++, temp = ar[i].second;
	}
	cout<<cnt<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
//
//	int t;
//	cin>>t;
//	while(t--)
	    solve();

	return 0;
}


