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
const int mxN = 1e6 + 5,mod = 1e9 + 7;
int dp[mxN][2]; // => dp(i) = a(i) <= [dp(i)(1)] + b(i) <= [dp(i)(0)]
void solve()
{
   	int n;
   	cin >> n;
   	dp[1][0] = 1;
   	dp[1][1] = 1;
   	for(int i = 2;n >= i;i++)
   	{
   		dp[i][0] = (dp[i-1][0] * 4 + dp[i-1][1]) % mod;
   		dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 2) % mod;
   	}

   	cout << (dp[n][0] + dp[n][1]) % mod << endl;

}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	//fr

	int t;
	t=1;
	cin >> t;
	while(t--) solve();

}