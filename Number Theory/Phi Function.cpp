#include<bits/stdc++.h>
using namespace std;
int phi(int n)
{
	int ans = n;
	for(int p = 2; p*p<=n;p++)
	{
		// Check p is a prime factor of n. 
		if(n % p == 0)
		{
			while(n % p == 0)
				n /= p; //divide all the factors of p
			ans -= ans/p;
		}
	}
	/*
	There can be only one prime 
	greater than sqrt(n) that divides n
	*/
	if(n > 1)
		ans -= ans/n;
	return ans;
}
int main()
{
	for(int i = 1; i <= 10; i++)
	{
		int res = phi(i);
		printf("Phi(%d): %d\n",i,res);
	}
	return 0;
}
