//Problem Link: https://codeforces.com/contest/1443/problem/B
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
void solve()
{
	int a, b;
	string s;
	cin>>a>>b>>s;
	vector<int> v;
	int cnt1 = 0, cnt0 = 0;
	for(int i = 0; i<sz(s); i++)
	{
		if((cnt1 > 0 && s[i] == '0') || (v.size()> 0 && s[i] == '0'))
		{
		
			if(cnt1>0)
			{
				v.pb(cnt1);
				cnt1 = 0;
			}
			cnt0++;
		}
		else if(s[i] == '1')
		{
			if(cnt0 > 0)
			{
				v.pb(cnt0);
				cnt0 = 0;
			}
			cnt1++;
		}
	}
	if(cnt1 > 0)
		v.pb(cnt1);
	if(v.size()==0)
	{
		cout<<"0\n";
		return;
	}
	ll ans = a;	
	for(int i = 1; i<sz(v); i+=2)
	{
		if(v[i]*b > a)
			ans+= a;
		else
			ans += b*v[i];
	}
	cout<<ans<<nl;
	
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
