#include<bits/stdc++.h>
using namespace std;
char ar[7][7], cpy[7][7];
int r, c, k;
void copy_matrix()
{
	for(int i = 0; i<r; i++)
		for(int j = 0; j<c; j++)
			cpy[i][j] = ar[i][j];
}
void color(int i, int j)
{
	for(int rr = 0; rr<r; rr++)
	{
		if(i & (1<<rr))
		{
			for(int cc = 0; cc<c; cc++)
				cpy[rr][cc] = '$';	
		}
	}
	for(int cc = 0; cc<c; cc++)
	{
		if(j & (1<<cc))
		{
			for(int rr = 0; rr<r; rr++)
				cpy[rr][cc] = '$';	
		}
	}
	
}
bool check()
{
	int cnt = 0;
	for(int i = 0; i<r; i++)
	{
		for(int j = 0; j<c; j++)
		{
			if(cpy[i][j] == '#')
				cnt++;
		}
	}
	if(cnt == k) return true;
	else return false;
}
void solve()
{
	cin>>r>>c>>k;
	
	for(int i = 0; i<r; i++)
		for(int j = 0; j<c; j++)
			cin>>ar[i][j];
		
	int ans  = 0;
	for(int i = 0; i<(1<<r); i++)
	{
		for(int j = 0; j<(1<<c); j++)
		{
			copy_matrix();
			color(i, j);
			if(check())
				ans++;
		}
	}
	cout<<ans<<"\n";
}
int main()
{
	solve();
	return 0;
}
