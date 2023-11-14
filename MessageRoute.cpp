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
void solve()
{
   	int n,m;
   	cin >> n >> m;
   	vector<int> adj[n];
   	int dist[n];
   	int prev[n];
   	int vis[n];
   	memset(vis,0,sizeof(vis));
   	vis[0] = 1;
   	for(int i = 0;n > i;i++) dist[i] = INF;
   	for(int i = 0;m > i;i++)
   	{
   		int x,y;
   		cin >> x >> y;
   		x--,y--;
   		adj[x].push_back(y);
   		adj[y].push_back(x);
   	}
   	priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq;
   	pq.push({0,0});
   	dist[0] = 0;
   	prev[0] = -1;
   	while(pq.size())
   	{
   		ar<int,2> piv = pq.top();
   		pq.pop();
   		
   		
   		for(auto it : adj[piv[1]])
   		{
   			if(dist[it] > piv[1] + 1)
   			{
   				prev[it] = piv[1];
   				dist[it] = piv[0] + 1;
   				if(vis[it] == 0)
   				{
   					pq.push({dist[it],it}) , vis[it] = 1;
   				//	cout << it << endl;
   				}
   				
   			}
   		}
   	}
   	if(dist[n-1] == INF)
   	{
   		cout << "IMPOSSIBLE" << endl;
   		return;
   	}
   	vector<int> ans;
   	for(int i = n-1;i >= 0;i = prev[i])
   	{
   		ans.push_back(i+1);
   	}
   	reverse(all(ans));
   	cout << ans.size() << endl;
   	for(auto it : ans) cout << it << " ";
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