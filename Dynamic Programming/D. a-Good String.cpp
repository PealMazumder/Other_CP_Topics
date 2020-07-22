//Problem Link: https://codeforces.com/problemset/problem/1385/D
#include<bits/stdc++.h>
#define ll long long
#define pb(x) push_back(x)
#define nl "\n"
using namespace std;
int n;
string s;
int needToChange(int l, int r, char ch)
{
	int cnt = 0;
	for(int i = l; i<=r; i++)
	{
		if(s[i] != ch)
			cnt++;
	}
	return cnt;
}
int minMoves(int l, int r, char ch)
{
	if(l == r && s[l] == ch) return 0;
	if(l == r && s[l] != ch) return 1;
	int mid = (l+r)/2;
	return min(needToChange(l, mid, ch) + minMoves(mid+1,r,ch+1), 
				needToChange(mid+1, r, ch) + minMoves(l, mid, ch+1));
}
void solve()
{
	cin>>n;
	cin>>s;
	int ans = minMoves(0,n-1,'a');
	cout<<ans<<nl;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);
	
	int t;
	cin>>t;
	while(t--)
	    solve();

	return 0;
}

