//Problem Link: http://codeforces.com/problemset/problem/489/C
#include<bits/stdc++.h>
#define	ll	long long
#define	pb	push_back
#define	sz(v)	(int)v.size()
#define	nl	"\n"
using namespace std;

void solve()
{
	string digits = "0123456789";
	string mx = "";
	int m, s;
	cin>>m>>s;
	if(m == 1 && s == 0)
	{
		cout<<"0 0\n";
		return;
	}
	if(s == 0)
	{
		cout<<"-1 -1\n";
		return;
	}
	for(int i = 0; i<m; i++)
	{
		for(int j = 9; j >= 0; j--)
		{
			if(s - j >= 0)
			{
				mx += digits[j];
				s -= j;
				break;
			}
		}
	}
	if(s > 0)
	{
		cout<<"-1 -1\n";
		return;
	}
	string rmx = mx;
	reverse(rmx.begin(), rmx.end());
	string start ="", end = ""; 
	int z = 0;
	for(int i = 0; i<m; i++)
	{
		if(start == "" && rmx[i] == '0')
			z++;
		else if(start == "")
			start += rmx[i];
		else
			end += rmx[i];
	}
	
	if(z == 0)
	{
		cout<<start+end<<" "<<mx<<nl;
		return;
	}
	int a = start[0] - '0' - 1;
	if(a > 0 && z > 0)
		start[0] = '1';
	cout<<start;
	int i;
	for(i = 0; i<z - 1; i++)
	{
		cout<<"0";
	}
	cout<<digits[a];
	cout<<end<<" "<<mx<<nl;
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


