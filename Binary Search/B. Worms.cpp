//Problem Link: https://codeforces.com/problemset/problem/474/B
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int binarySearch(vector<int> &ar, int target, bool type)
{
	int left = 0, right = ar.size() - 1,idx = -1;
  	while(left <= right)
  	{
    // Prevent (left + right) overflow
    	int mid = left + (right - left) / 2;
    
   	 if(ar[mid] == target)
    {
    	idx = mid;
    	if(type == 0)
    		right = mid - 1;/// Lower bound
    	else left = mid + 1;///Upper bound
	}
	else if(ar[mid] < target) 
		left = mid + 1;
    else
		right = mid - 1;	
  	}
  	
  	if(idx < 0) return left;
	if(type == 1) return idx+1;///Upper bound
  	return idx;/// Lower bound
}
void solve()
{
	ll n, m, q;
	cin>>n;
	vector<int> ar(n);
	for(int i = 0; i<n; i++)
		cin>>ar[i];
	cin>>m;
	for(int i = 1; i<n; i++)
		ar[i] += ar[i-1];
	while(m--)
	{
		cin>>q;
		int lwr = binarySearch(ar, q, 0); //type = '0'/zero for lower_bound
//		auto low = lower_bound(ar.begin(), ar.end(), q);
//		cout<<low - ar.begin() + 1<<nl;
		cout<<lwr+1<<nl;
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

//	int t;
//	cin>>t;
//	while(t--)
	    solve();

	return 0;
}

