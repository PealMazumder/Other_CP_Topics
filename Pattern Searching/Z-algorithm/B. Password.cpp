/*
	Problem Link: https://codeforces.com/contest/126/problem/B
	Tutorials on Z-algorithm: 
							https://cp-algorithms.com/string/z-function.html
							https://www.youtube.com/watch?v=CpZh4eF8QBw&list=PLrmLmBdmIlpvm7VaC0NTR27A_3i2sU3zd&index=3
				
*/
#include<bits/stdc++.h>
#define	fast						ios::sync_with_stdio(false);cin.tie(0);cout.tie(NULL);
#define all(p)						p.begin(),p.end()
#define sz(c)						(int)c.size()
#define pb(x)						push_back(x)
#define ll						long long
#define nl						"\n"
using namespace std;
const int INF = 0x7f7f7f7f;
const int modu = 1e9 + 7;
const int N = 1e6+7;
vector<int> z(N);
vector<int> suf;
vector<int> mid;

void zAlgorithm(string const& s, int len)
{
	bool ck = false;
	for(int i = 1, l = 0, r = 0; i<len; i++)
	{
		if(i<=r)
			z[i] = min(r - i + 1, z[i - l]);
		while(i + z[i] < len && s[z[i]] == s[i + z[i]])
			++z[i];
		if(i + z[i] - 1 > r)
			l = i, r = i + z[i] -1;
		if(z[i] == len-i)
		{
			ck = true;
			suf.pb(z[i]);
		}
		else if(ck == true && z[i] != len-i)
			z[i] = 0;
		else if(z[i] != 0)
			mid.pb(z[i]);
	}
}
void solve(string s)
{
	int len = sz(s);
	zAlgorithm(s,len);
	sort(all(mid), greater<int>());
	sort(all(suf),greater<int>());
	if(mid.empty() && sz(suf)>1)
	{
		cout<<s.substr(0,suf[1]);
		return;
	}
	for(int i = 0; i<sz(suf); i++)
	{
		for(int j = 0; j <sz(mid); j++)
			if(suf[i]<=mid[j])
			{
				cout<<s.substr(0,suf[i]);
				return;
			}
	}
	cout<<"Just a legend\n";
}
int main()
{
	fast
	string s;
	cin>>s;
	solve(s);		
    return 0;
}


