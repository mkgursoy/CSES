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
const int mxN = 1e5 + 5;
int n,m,val[mxN],vis[mxN];
vector<int> adj[mxN];
void dfs(int pos,int color)
{
	val[pos] = color;
	vis[pos] = 1;
	color += 1;
	color %= 2;
	for(auto it : adj[pos])
	{
		if(vis[it])
		{
			if(val[pos] == val[it])
			{
				cout << "IMPOSSIBLE" << endl;
				exit(0);
			}
			
		}
		else dfs(it,color);
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
   		if(!vis[i])
   		{
   			dfs(i,0);
   		}
   	}
   	for(int i = 0;n > i;i++)
   	{
   		cout << val[i] + 1 << " ";
   	}

}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	//fr

	int t;
	t=1;
//	cin >> t;
	while(t--) solve();

}