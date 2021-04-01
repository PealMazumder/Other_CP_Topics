//Problem Link: https://lightoj.com/problem/trailing-zeroes-iii
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
#define sz(x) (int)x.size()
#define	all(p) p.begin(),p.end()
using namespace std;
int casino = 0;
int trailingZeroes(int x)
{
	int ans = 0;
	while(x)
	{
		ans += x/5;
		x/=5;
	}
	return ans;
}
void solve()
{
	int q;
	cin>>q;
	int l = 1, r = 500000000;
	while(l < r)
	{
		int mid = (l+r)/2;
		int ans = trailingZeroes(mid);
		if(ans < q) l = mid+1;
		else r = mid;
	}
	int ans = trailingZeroes(l); 
	cout<<"Case "<<++casino<<": ";
	if(q == ans)
		cout<<l<<nl;
	else	cout<<"impossible\n";
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}

