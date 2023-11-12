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
const int mod = (int)1e9 + 7;
void solve()
{
   	int n;
   	cin >> n;
   	int dp[n+1];
   	dp[0] = 1;

   	for(int i = 1;n >= i;i++)
   	{
   		dp[i] = 0;
   		for(int j = 1;min(i,6ll) >= j;j++)
   		{
   			dp[i] += dp[i-j];
   			dp[i] %= mod;
   		}

   		//cout << dp[i] << " ";
   	}
   	cout << dp[n] << endl;
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