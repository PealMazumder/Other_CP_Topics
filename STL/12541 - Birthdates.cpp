#include<bits/stdc++.h>
//Problem Link: https://onlinejudge.org/external/125/12541.pdf
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
#define		no				cout<<"No\n"
#define		yes				cout<<"Yes\n"
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
struct person
{
	string name;
	int d;
	int m;
	int y;	
};
bool comp(person a, person b)
{
	if(a.y < b.y || (a.y == b.y && a.m < b.m) ||(a.y == b.y && a.m == b.m && a.d < b.d)) return false;
	else return true;
}
void solve()
{
	int n, d, m, y;
	string s;
	cin>>n;
	vector<person> v;
	for(int i = 0; i<n; i++)
	{
		cin>>s>>d>>m>>y;
		v.pb({s, d, m, y});
	}
	sort(all(v), comp);
	cout<<v.front().name<<nl;
	cout<<v.back().name<<nl;
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
