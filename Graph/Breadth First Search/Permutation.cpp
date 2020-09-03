/*
Problem Link: https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/algorithm/t1-1-6064aa64/
*/
#include<bits/stdc++.h>
#define all(p)					p.begin(),p.end()
#define mem(p, v)				memset(p, v, sizeof(p))
#define sz(c)					(int)c.size()
#define pb(x) 					push_back(x)
#define ll 						long long
#define nl 						"\n"
#define FI                      freopen("input.txt", "r", stdin);
#define FO                      freopen("output.txt", "w", stdout);
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(NULL);

	int n;
	cin>>n;
	string initial = "";
	for(int i = 0; i < n; i++)
	{
		int x;
		cin>>x;
		initial += ('0'+x);
	}
	string req = initial;
	sort(req.begin(),req.end());

	queue <string> q;
	q.push(initial);

	map<string, int> m;
	m[initial] = 0;

	while(!q.empty())
	{
		string nxt = q.front();
		q.pop();

		if(nxt == req)
		{
			cout<<m[nxt]<<nl;
			break;
		}

		for(int i = 2; i<=n; i++)
		{
			string v = nxt;
			reverse(v.begin(), v.begin()+i);

			if(m.find(v) == m.end())
			{
				m[v] = m[nxt] + 1;
				q.push(v);
			}
		}
	}

	return 0;
}
