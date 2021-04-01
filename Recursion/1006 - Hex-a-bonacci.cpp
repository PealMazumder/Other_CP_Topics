/*
	http://www.shafaetsplanet.com/?p=1022
	This article may help you.
*/
#include<bits/stdc++.h>
#define nl "\n"
#define ll long long
using namespace std;
ll a, b, c, d, e, f;
ll dp[10001];
int fn( int n ) {
    for(int i = 0;i<=n;i++)
    {
    	if( i == 0 ){
    		dp[i] = a;
		} 
	    else if( i == 1 ) {
    		dp[i] = b;
		}
	    else if( i == 2 ) {
    		dp[i] = c;
		}
	    else if( i == 3 ) {
    		dp[i] = d;
		}
	    else if( i == 4 ) {
    		dp[i] = e;
		}
	    else if( i == 5 ) {
    		dp[i] = f;
		}
		else
			dp[i] = (dp[i-1]+dp[i-2]+dp[i-3]+dp[i-4]+dp[i-5]+dp[i-6])% 10000007;
	}
	return dp[n];
}
int main()
{
    ll t,n,caseno = 0,res;
    
    cin>>t;
    while( t-- ) {
        cin>>a>>b>>c>>d>>e>>f>>n;
        res = fn(n);
        cout<<"Case "<<++caseno<<": "<<res% 10000007<<nl;
    }
    return 0;
}

