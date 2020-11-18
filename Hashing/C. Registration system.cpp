///https://codeforces.com/problemset/problem/4/C
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;

void solve()
{
	ll n, x;
	cin>>n;
	map<string, int> mp;
	string s;
	for(ll i = 0; i<n; i++)
	{
		cin>>s;
		if(mp[s] == 0)
		{
			cout<<"OK\n";
			mp[s]++;
		}
		else
		{
			cout<<s<<mp[s]<<nl;
			mp[s]++;
		}
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

