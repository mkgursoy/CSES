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
const int mxN = 1000;
const int mod = (int)1e9 + 7;
int dp[mxN][mxN];
void solve()
{
   	int n;
   	cin >> n;
   	string s[n];
   	for(int i = 0;n > i;i++) cin >> s[i];
   	if(s[0][0] == '*' || s[n-1][n-1] == '*')
   	{
   		cout << "0" << endl;
   		return;
   	}
   	dp[0][0] = 1;
   	for(int i = 1;n > i;i++)
   	{
   		if(s[i][0] == '.')
   		dp[i][0] = dp[i-1][0];
   		if(s[0][i] == '.')
   		dp[0][i] = dp[0][i-1];
   	}
   	for(int i = 1;n > i;i++)
   	{
   		for(int j = 1;n > j;j++)
   		{
   			if(s[i][j] == '.')
   			dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;

   			//cout << dp[i][j] << " ";
   		}
   	//	cout << endl;

   	}
   	cout << dp[n-1][n-1] << endl;
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