//Problem LinK: https://lightoj.com/problem/double-ended-queue
#include<bits/stdc++.h>
#define		nl				"\n"
#define		mod				1000000007
#define		sz(c)			(int)c.size()
#define		pb				push_back
#define		ff				first
#define		ss				second
#define		mkp				make_pair
#define		ll				long long
#define		pii				pair<int, int>
#define 	pll				pair<ll, ll>
#define 	vll				vector<ll>
#define 	vi				vector<int>
#define		no				cout<<"NO\n"
#define		yes				cout<<"YES\n"
#define		one				cout<<"1\n"
#define		mone			cout<<"-1\n"
#define		gcd(a, b)		__gcd(a, b)
#define		total_bit(a)	__builtin_popcount(a)
#define		lcm(a, b)		((a)*((b)/gcd(a,b)))
#define		REP(i,n)		for(int i = 0; i<n; i++)
#define		all(p)			p.begin(),p.end()
#define		mem(ar,val)		memset(ar, val, sizeof(ar))
#define 	UNIQUE(a)		sort(all(a)); a.erase(unique(all(a)), a.end())
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const double pi = acos(-1.0);
const ll INF = 1000000000000000000;
const int N = 1e6+7;
int casino = 0;
void solve()
{
	int n, m;
	cin>>n>>m;
	deque<int> d;
	cout<<"Case "<<++casino<<":\n";
	string s; int val;
	while(m--)
	{
		cin>>s;
		if(s == "pushLeft" || s == "pushRight")
		{
			cin>>val;
			if(d.size() == n)
			{
				cout<<"The queue is full\n";
			}
			else if(s == "pushLeft")
			{
				d.push_front(val);
				cout<<"Pushed in left: "<<val<<nl;
			}
			else
			{
				d.push_back(val);
				cout<<"Pushed in right: "<<val<<nl;
			}
		}
		else
		{
			if(d.empty())
			{
				cout<<"The queue is empty\n";
			}
			else if(s == "popLeft")
			{
				cout<<"Popped from left: "<<d.front()<<nl;
				d.pop_front();
			}
			else
			{
				cout<<"Popped from right: "<<d.back()<<nl;
				d.pop_back();
			}
		}
	}
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	ll t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
