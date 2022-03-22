///Problem Link: https://www.spoj.com/problems/RMID2/
#include<bits/stdc++.h>
#define	nl	"\n"
using namespace std;

void solve()
{
	priority_queue<int> mx;
	priority_queue<int, vector<int>, greater<int> > mn;
	int n;
	while(true)
	{
		cin>>n;
		if(n == 0) return;
		else if(n < 0)
		{
            cout<<mx.top()<<nl;
            mx.pop();
            if(!mn.empty() && mx.size() != mn.size())
            {
                mx.push(mn.top());
                mn.pop();
            }
		}
		else
		{
			if(mx.empty() || n < mx.top())
				mx.push(n);
			else
				mn.push(n);
			if(mx.size()>mn.size()+1)
			{
				mn.push(mx.top());
				mx.pop();
			}
			if(mx.size() < mn.size())
			{
				mx.push(mn.top());
				mn.pop();
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(NULL);

	int t;
	cin>>t;
	while(t--)
	    solve();

	return 0;
}

