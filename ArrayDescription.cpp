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
 
int mxn = 1e18;
int mnn = -mxn;
 
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
const int mxN = 1e5 + 5,mxM = 1e2 + 5,mod = 1e9 + 7;
int dp[mxN][mxM];
void solve()
{
   	int n,m;
   	cin >> n >> m;
   	int a[n];
   	for(int i = 0;n > i;i++)
   	{
   		cin >> a[i];
   	}
  	if(a[0] == 0)
  	{
  		for(int i = 1;m >= i;i++) dp[0][i] = 1;
  	}
  	else
  		dp[0][a[0]] = 1;
 
  	for(int i = 1;n > i;i++)
  	{
  		if(a[i] == 0)
  		{
  			for(int j = 1;m >= j;j++)
  			{									
  				dp[i][j] = (dp[i-1][j-1]%mod + dp[i-1][j+1]%mod + dp[i-1][j]%mod)%mod;
  			}
  		}
  		else
  		{			
  			dp[i][a[i]] = (dp[i-1][a[i]-1]%mod + dp[i-1][a[i]+1]%mod + dp[i-1][a[i]]%mod)%mod;
  		}
  	}
  	int ans = 0;
   	for(int i = 0;m >= i;i++)
   	{
   		ans += dp[n-1][i]%mod;
   		ans %= mod;
   	}
   	cout << ans << endl;
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