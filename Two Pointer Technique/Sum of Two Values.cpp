//Problem Link: https://cses.fi/problemset/task/1640/
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;

void solve()
{
	int n, x, a;
	cin>>n>>x;
	vector<pair<int, int> > ar;
	for(int i = 0; i<n; i++)
		cin>>a, ar.pb({a, i+1});
	sort(ar.begin(), ar.end());
	int l = 0, r = n-1;
	while(l < r)
	{
		if(ar[l].first + ar[r].first == x)
		{
			if(ar[l].second < ar[r].second)
				cout<<ar[l].second<<" "<<ar[r].second<<nl;
			else
				cout<<ar[r].second<<" "<<ar[l].second<<nl;	
			return;
		}
		else if(ar[l].first + ar[r].first > x)
			r--;
		else l++;
	}
	cout<<"IMPOSSIBLE\n";
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


