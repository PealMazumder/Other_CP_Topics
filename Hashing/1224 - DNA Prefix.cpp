//Problem Link: http://lightoj.com/volume_showproblem.php?problem=1224
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int casino = 0;
void solve()
{
	int n;
	scanf("%d", &n);
	char s[50];
	unordered_map<ll, int> mp;
	int ans = 0;
	const int p = 31;
	const int m = 1e9 + 9;
	for(int i = 0; i<n; i++)
	{
		scanf("%s", s);
		ll hash_value = 0;
	    	ll p_pow = 1;
		for(int j = 0; j<strlen(s); j++)
		{
			hash_value = (hash_value + (s[j] - 'a' + 1) * p_pow) % m;
	        	p_pow = (p_pow * p) % m;
			mp[hash_value]++;
			ans = max(ans, mp[hash_value] * (j+1));
		}
	}
	printf("Case %d: %d\n", ++casino, ans);
	
}
int main()
{
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(NULL);

	int t;
	scanf("%d", &t);
	while(t--)
	    solve();

	return 0;
}


