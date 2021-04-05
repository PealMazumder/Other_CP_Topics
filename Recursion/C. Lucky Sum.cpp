//Problem Link: https://codeforces.com/contest/122/problem/C
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define sz(x) (int)x.size()
#define	all(p) p.begin(),p.end()

using namespace std;
ll l, r;
set<ll> st;
ll mx = 1e9;
ll CONV(string s)
{
	ll sum = 0;
	for(auto ch : s)
		sum = sum * 10 + (ch-'0');
	return sum;
}
void subs(string input, string output)
{
	if(CONV(output) > mx) return;
	if(input.empty() && CONV(output) <= mx)
	{
		st.insert(CONV(output));
		return;
	}
	subs(input.substr(1), output);
	subs(input.substr(1), output + input[0]);
}
void solve()
{
	cin>>l>>r;
	string input = "774477447744774477447744";
//	cout<<sz(input)<<nl;
	subs(input, "");
	ll sum = 0, cnt = 0;
	st.insert(4444444444);
//	for(auto xx : st)
//		cout<<xx<<" ";
	while(l <= r)
	{
		auto idl = st.lower_bound(l);
		ll dif;
//		cout<<*idl<<nl;
		if(*idl <= r)
			dif = *idl - l + 1, l = (*idl) + 1LL;
		else dif = r - l + 1, l = r + 1LL;
		sum += dif*(*idl);
//		cout<<dif*(*idl)<<nl;
	}
	cout<<sum<<nl;
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
//	ll t;
//	cin>>t;
//	while(t--)
		solve();
	return 0;
}

