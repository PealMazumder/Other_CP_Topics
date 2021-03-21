//Problem Link: https://codeforces.com/problemset/problem/69/E
#include<bits/stdc++.h>
#define		nl				"\n"
#define		sz(c)			(int)c.size()
#define		pb				push_back
#define		ll				long long

using namespace std;
void solve()
{
	ll i, j,  n, k;
	cin>>n>>k;
	ll ar[n];
	for(i = 0; i<n; i++)
	{
		cin>>ar[i];
	}
	map<ll, ll>neg, pos;
	set<ll> st;
	for(i = 0; i<k; i++)
	{
		if(ar[i] < 0)
		{
			neg[abs(ar[i])]++;
			if(neg[abs(ar[i])] < 2)
				st.insert(ar[i]);
			else
				st.erase(ar[i]);	
		}
		else
		{
			pos[ar[i]]++;
			if(pos[ar[i]] < 2)
				st.insert(ar[i]);
			else st.erase(ar[i]);
		}
	}
	ll l = 0, r = k;
	if(st.empty())
		cout<<"Nothing\n";
	else
		cout<<*st.rbegin()<<nl;
	while(r<n)
	{
		if(ar[l] < 0)
		{
			neg[abs(ar[l])]--;
			if(neg[abs(ar[l])] == 0)
				st.erase(ar[l]);
			else if(neg[abs(ar[l])] == 1)
				st.insert(ar[l]);
		}
		else
		{
			pos[ar[l]]--;
			if(pos[ar[l]] == 0)
				st.erase(ar[l]);
			else if(pos[ar[l]] == 1)
				st.insert(ar[l]);
		}
		if(ar[r] < 0)
		{
			neg[abs(ar[r])]++;
			if(neg[abs(ar[r])] < 2)
				st.insert(ar[r]);
			else
				st.erase(ar[r]);	
		}
		else
		{
			pos[ar[r]]++;
//			cout<<r<<" "<<pos[ar[r]]<<nl;
			if(pos[ar[r]] < 2)
				st.insert(ar[r]);
			else st.erase(ar[r]);
		}
		
		if(st.empty())
			cout<<"Nothing\n";
		else
			cout<<*st.rbegin()<<nl;
			
		l++, r++;
	}
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
