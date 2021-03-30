//Problem Link: https://www.spoj.com/problems/ADAQUEUE/en/
#include<bits/stdc++.h>
#define		nl				"\n"
#define		sz(c)			(int)c.size()
#define		pb				push_back
#define		ff				first
#define		ss				second
#define		ll				long long
#define		all(p)			p.begin(),p.end())
using namespace std;
const int N = 1e6+7;
int casino = 0;
void solve()
{
	ll n, x, d, k, i, j;
	cin>>n;
	string s;
	ll cnt = 0;
	deque<ll> dq;
	while(n--)
	{
		cin>>s;
		if(s == "toFront" || s == "push_back")
		{
			cin>>x;
			if(cnt & 1)
			{
				if(s == "toFront") dq.push_back(x);
				else dq.push_front(x);
			}
			else if(s == "toFront")
				dq.push_front(x);
			else
				dq.push_back(x);
		}
		else if(s == "reverse") cnt++;
		else if(s == "front")
		{
			if(dq.empty())
				cout<<"No job for Ada?\n";
			else if(cnt & 1)
				cout<<dq.back()<<nl, dq.pop_back();
			else cout<<dq.front()<<nl, dq.pop_front();
		}
		else
		{
			if(dq.empty())
				cout<<"No job for Ada?\n";
			else if(cnt & 1)
				cout<<dq.front()<<nl,dq.pop_front();
			else cout<<dq.back()<<nl, dq.pop_back();
		}
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
