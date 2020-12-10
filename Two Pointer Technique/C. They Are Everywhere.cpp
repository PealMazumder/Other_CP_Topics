/*
	Problem Link: https://codeforces.com/problemset/problem/701/C
	Difficulty: 1500
*/
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;

void solve()
{
	int n;
	string s;
	cin>>n>>s;
	map<char, bool> mp;
	int tot = 0; 
	for(int i = 0; i<n; i++)
	{
		if(mp[s[i]] == false)
		{
			tot++;
			mp[s[i]] = true;
		}
	}
	int ans = INT_MAX, l = 0, r = 0, cnt = 0;
	map<char, bool>ck;
	map<char, int> c;
	while(r<n)
	{
		if(ck[s[r]] == false)
		{
			c[s[r]]++;
			cnt++;
			ck[s[r]] = true;
		}
		else
		{
			while(s[l] == s[r] && l < r)
			{
				c[s[l]]--;
				l++;
			}
			c[s[r]]++;
		}
		if(cnt == tot)
		{
			ans = min(ans, r - l +1);
//			cout<<r<<" "<<l<<" "<<s[r]<<nl;
			while(c[s[l]] > 1 )
			{
				c[s[l]]--;
				l++;
			}
			ans = min(ans, r - l +1);
			c[s[l]]--;
			ck[s[l]]=false;
			l++;
			cnt--;
			while(l+1 <= r&&s[l] == s[l+1])
			{
				c[s[l]]--;
				l++;
			}
			
		}
		r++;
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


