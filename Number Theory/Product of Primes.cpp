//Problem Link: https://practice.geeksforgeeks.org/problems/product-of-primes5328/1
#include <bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;
const int mx = 32000;
const ll mod = 1e9 + 7;
class Solution{
public:

    vector<int> prime;
    void sieve()
    {
        bool vis[mx] = {false};
    	int x = mx;
    	for(int i = 3; i*i <= mx; i += 2)
    	{
    		if(vis[i] == 0)
    		{
    			for(int j = i*i; j<mx; j += 2*i)
    				vis[j] = 1;
    		}
    	}
    	prime.pb(2);
    	for(int i = 3; i<mx; i += 2)
    		if(vis[i] == 0)
    			prime.pb(i);
    }
    long long primeProduct(long long a, long long b){

        sieve();

    	if(b < 2)
            return 1;
    	if(a < 2) a = 2;
    	ll x = sqrt(b) + 1;
    	bool vis[b-a+1];
    	memset(vis,0,sizeof(vis));
    	for(ll i = 0; i < prime.size() && prime[i] <= x; i++)
    	{
    		ll j = prime[i] * prime[i];
    		if(j < a) // If j is smaller than a, then shift it inside of segment [a,b]
    			j = ((a + prime[i] - 1)/prime[i]) * prime[i];

    		while(j <= b)
    		{
    			vis[j-a] = 1;
    			j += prime[i];
    		}

    	}
    	ll ans = 1;
    	for(ll i = a; i <= b; i++)
    		if(vis[i-a] == 0) ans = (ans * i) % mod;
        return ans;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        long long L, R;
        cin>>L>>R;

        Solution ob;
        cout<<ob.primeProduct(L, R)<<"\n";
    }
    return 0;
}
