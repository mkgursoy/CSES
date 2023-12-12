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

int INF = 1e16;

void setIO(string name = "") 
{
	if (name.size())
	{
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
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
const int mxN = 1e5 + 7;
int dist[mxN];
int vis[mxN];
void solve()
{
   	int n,m;
   	cin >> n >> m;
   	vector<ar<int,2>> adj[n+1];
   	while(m--)
   	{
   		int x,y,z;
   		cin >> x >> y >> z;
   		adj[x].push_back({y,z});
   	}
   	priority_queue<ar<int,2>,vector<ar<int,2>>,greater<ar<int,2>>> pq;
   	pq.push({0,1});
   	for(int i = 2;n >= i;i++) dist[i] = INF;
   	dist[1] = 0;
   	vis[1] = 0;   	
   	while(pq.size())
   	{
   		int piv = pq.top()[1]; 
   		pq.pop(); 		
   		if(vis[piv]) continue;
   		vis[piv] = 1;
   		for(auto it : adj[piv])
   		{
   			if(dist[it[0]] > dist[piv] + it[1])
   			{
   				//cout << dist[it[0]] << " " << it[0] << " " << dist[piv] << " " << it[1] << endl;
   				dist[it[0]] = dist[piv] + it[1];
   				pq.push({dist[it[0]],it[0]});
   				
   			}
   		}
   	}
   	for(int i = 1;n >= i;i++) cout << dist[i] << " ";
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