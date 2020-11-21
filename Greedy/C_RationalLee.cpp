//Problem Link: https://codeforces.com/contest/1369/problem/C
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int comp(int a, int b)
{
	return a>b;
}
void solve()
{
	ll n, x, k;
	cin>>n>>k;
	ll ar[n], w[k];
	
	for(int i = 0; i<n; i++)
		cin>>ar[i];
	for(int i = 0; i<k; i++)
		cin>>w[i];
		
	sort(ar, ar+n);
	sort(w, w+k);
	
	ll sum = 0, id = -1;
	
	for(int i = n-1, j = 0;j<k && i>=n-k; i--, j++)
	{
		sum += ar[i], w[j]--;
		if(w[j] == 0) sum += ar[i];
		if(id == -1 && w[j] != 0) id = j;

	}
	
	if(id == -1)
	{
		cout<<sum<<nl;
		return;
	}
	
	for(int i = k-1, j = 0; i >= id; i--)
	{
		sum += ar[j];
		j += w[i]; 
	}
	cout<<sum<<nl;
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

