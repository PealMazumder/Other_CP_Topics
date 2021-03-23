// Problem Link: https://www.hackerrank.com/challenges/cpp-sets/problem
#include<bits/stdc++.h>
#define		nl				"\n"
using namespace std;
void solve()
{
	int q, x, y;
	cin>>q;
	set<int> st;
	while(q--)
	{
		cin>>x>>y;
		if(x == 1)
		{
			st.insert(y);
		}
		else if(x == 2)
			st.erase(y);
		else
		{
			if(st.find(y) != st.end())
				cout<<"Yes\n";
			else cout<<"No\n";
		}
	}
	
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
//	ll t;
//	cin>>t;
//	while(t--)
		solve();
	return 0;
}
