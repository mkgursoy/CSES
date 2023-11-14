/*
    Author:Matkap(prefixsumenjoyer23)
    
*/

#include <bits/stdc++.h>
#include <array>

using namespace std;

#define fr freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);
#define int long long
#define endl "\n"
#define ar array
#define all(x) x.begin(),x.end()

int INF = 1e18;

int binpow(int base,int power)
{
	if(power == 1) return base;
	if(power == 0) return 1;
    
     if(power%2==1)
     {
     	 int a;
     	a = binpow(base,(power-1)/2);
     	return a*a*base;
     } 
     else
     {
     	 int a;
     	a = binpow(base,power/2);
     	return a*a;
     } 

}
const int mxN = 1e5 + 5,mxM = 1e5 + 5;
vector<int> adj[mxN];
int vis[mxN];
int n;
void dfs(int i)
{
	vis[i] = 1;
	for(auto it : adj[i])
	{
		if(!vis[it]) dfs(it);
	}
}
void solve()
{
	int m;
	cin >> n >> m;
	int cnt = 0;
	int prev;
	for(int i = 0;m > i;i++)
	{
		int x,y;
		cin >> x >> y;
		x--,y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	vector<ar<int,2>> ans;
	for(int i = 0;n > i;i++)
	{
			if(!vis[i])
			{
				if(cnt == 0) prev = i;
				else
				{
					ans.push_back({prev+1,i+1}),prev = i;
				}
				cnt += 1;
				dfs(i);
			
		}
	}

	cout << cnt-1 << endl;
	for(auto it : ans) cout << it[0] << " " << it[1] << endl;
}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	//fr

	int t;
	t=1;
	//cin >> t;
	while(t--) solve();

}