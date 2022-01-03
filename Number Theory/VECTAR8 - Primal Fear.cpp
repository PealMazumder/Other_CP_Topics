//Problem Link: https://www.spoj.com/problems/VECTAR8/
#include<bits/stdc++.h>
using namespace std;
const int N = 1000005;
bool vis[N];
int good[N];
bool ok(int n)
{
    int nums = 0, mul = 1, tm;
    while(n)
    {
        tm = n % 10;
        nums = nums + tm * mul;
        if(tm == 0 || vis[nums]) return false;
        n /= 10;
        mul *= 10;
    }
    return true;
}
void sieve()
{
    int i, j;
    vis[0] = vis[1] = true;
	for(int i = 4; i <= N; i += 2)
		vis[i] = true;
	for(i = 3; i * i <= N; i += 2)
	{
		if(!vis[i])
		{
			for(j = i * i; j <= N; j += 2 * i)
				vis[j] = true;
		}
	}
	good[2] = 1;
	for(i = 3; i < N; i++)
    {
        if(!vis[i])
        {
            if(ok(i))
                good[i] = good[i-1] + 1;
            else good[i] = good[i-1];
        }
        else good[i] = good[i-1];
    }
}
void solve()
{
    int n;
    cin>>n;
    cout<<good[n]<<"\n";

}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(NULL);
    sieve();
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
