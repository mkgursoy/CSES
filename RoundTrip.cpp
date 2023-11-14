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
const int mxN = 10e5 + 5;
int n,m,vis[mxN];
vector<int> adj[mxN];
int pre[mxN];
void dfs(int pos,int from)
{
	vis[pos] = 1;
	for(auto it : adj[pos])
	{
		if(it == from) continue;
		if(vis[it] != 0)
		{
			vector<int> ans;
			ans.push_back(it+1);
			while(pos != it && pos != -1)
			{			
				ans.push_back(pos+1);
				pos = pre[pos];
			}
			ans.push_back(it+1);
			cout << ans.size() << endl;
			for(auto it : ans) cout << it << " ";
			exit(0);
		}
		else
		{
			vis[it] = 1;
			pre[it] = pos;
			dfs(it,pos);
		}
	}
}
void solve()
{
   	cin >> n >> m;
   	while(m--)
   	{
   		int x,y;
   		cin >> x >> y;
   		x--,y--;
   		adj[x].push_back(y);
   		adj[y].push_back(x);
   	}
   	for(int i = 0;n > i;i++)
   	{
   		if(!vis[i]) dfs(i,-1),pre[i] = -1;
   	}
   	cout << "IMPOSSIBLE" << endl;
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