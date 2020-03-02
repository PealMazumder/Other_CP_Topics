/*
	Problem Link: https://www.codechef.com/problems/SWAPPALI
*/
#include<bits/stdc++.h>
#define nl						"\n"
using namespace std;
const int INF = 0x7f7f7f7f;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		string s;
		cin>>n>>s;
		int l=0, r = n-1,cnt = 0;
		bool ckl = true, ckr = true;
		while(l<r)
		{
			if(s[l] == s[r])
			{
				ckl = ckr = true;
				l++,r--;
				continue;
			}
			if(l+1 == r)
			{
				cout<<"NO\n";
				break;
			}
			if(ckl && s[l+1] == s[r])
			{
				swap(s[l],s[l+1]);
				ckl = false;
				ckr = true;	
				cnt++;
			}
			else if(ckr && s[r-1] == s[l])
			{
				swap(s[r],s[r-1]);
				ckr = false;
				ckl = true;
				cnt++;
			}
			else
			{
				cout<<"NO\n";
				break;
			}
			l++,r--;
		}
		if(l>=r)
			cout<<"YES\n"<<cnt<<nl;
	}
    return 0;
}


