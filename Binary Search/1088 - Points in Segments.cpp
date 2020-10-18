///Problem Link: http://lightoj.com/volume_showproblem.php?problem=1088
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
int casino = 0;
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
	int n, a, b, q;
	scanf("%d %d", &n, &q);
	vector<int> ar(n);
	for(int i = 0; i<n; i++)
		scanf("%d", &ar[i]);
	printf("Case %d:\n", ++casino);
	while(q--)
	{
		scanf("%d %d",&a, &b);
		int lwr = binarySearch(ar, a, 0);
		int upr = binarySearch(ar, b, 1);
		printf("%d\n", upr - lwr);
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	    solve();

	return 0;
}


