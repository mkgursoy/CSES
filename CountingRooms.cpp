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
const int mxN = 1e3 + 5,mxM = 1e3 + 5;
string s[mxN];
int vis[mxN][mxM];
int n,m;
bool check(int i,int j)
{
	if(n > i && i >= 0 && m > j && j >= 0 && vis[i][j] == 0 && s[i][j] == '.') return true;
	else
		return false;
}
void dfs(int i,int j)
{
	vis[i][j] = 1;
	if(check(i+1,j)) dfs(i+1,j);
	if(check(i-1,j)) dfs(i-1,j);
	if(check(i,j-1)) dfs(i,j-1);
	if(check(i,j+1)) dfs(i,j+1);
}
void solve()
{
	cin >> n >> m;
	int cnt = 0;
	for(int i = 0;n > i;i++) cin >> s[i];
	for(int i = 0;n > i;i++)
	{
		for(int j = 0;m > j;j++)
		{
			if(!vis[i][j] && s[i][j] == '.')
			{
				cnt += 1;
				dfs(i,j);
			}
		}
	}
	cout << cnt << endl;

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