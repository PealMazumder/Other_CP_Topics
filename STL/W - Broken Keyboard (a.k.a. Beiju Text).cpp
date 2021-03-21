//https://onlinejudge.org/external/119/11988.pdf
#include<bits/stdc++.h>
#define		nl				"\n"
#define		sz(c)			(int)c.size()
using namespace std;
int casino = 0;
void solve()
{
	string s;
	while(cin>>s)
	{
		s+="]";
		deque<string> dq;
		string a = "";
		bool ck = 1;
		for(int i = 0; i<sz(s); i++)
		{
			if(s[i] == '[')
			{
				if(a != "")
				{
					if(ck == 1)
						dq.push_back(a);
					else dq.push_front(a);
				}
				a = "";
				ck = 0;
			}
			else if(s[i] == ']')
			{
				if(a != "")
				{
					if(ck == 1)
						dq.push_back(a);
					else dq.push_front(a);
				}
				a = "";
				ck = 1;
			}
			else a += s[i];
		}
		
		
		while(!dq.empty())
		{
			cout<<dq.front();
			dq.pop_front();
		}
		cout<<nl;
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
