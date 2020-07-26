#include<bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define nl "\n"
using namespace std;
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
void solve()
{
	int n;
	cin>>n;
	int a[n];
	for(int i = 0; i<n; i++)
		cin>>a[i];
	int ans = 0;
	ordered_set <int> s;
	for(int i = n - 1; i>=0; i--)
	{
		ans += s.order_of_key(a[i]);
		s.insert(a[i]);
	}
	cout<<ans<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	
	solve();

	return 0;
}
