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

int mxn = 1e16;
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
const int mxA = 505,mxB = 505;
int dp[mxA][mxB];
void solve()
{
   	int a,b;
   	cin >> a >> b;
   	for(int i = 1;a >= i;i++)
   	{
   		for(int j = 1; b >= j; j++)
   		{
   			if(i == j)
   			{
 				dp[i][j] = 1;  				
   				continue;
   			}
   			dp[i][j] = mxn;
   			//Horizontal
   			for(int k = 1;i >= k;k++)
   			{
   				dp[i][j] = min(dp[i][j],dp[i-k][j] + dp[k][j]);
   			}
   			//Vertical
   			for(int k = 0;j >= k;k++)
   			{
   				dp[i][j] = min(dp[i][j],dp[i][j-k] + dp[i][k]);
   			}
   		}
   	}
   	cout << dp[a][b] - 1 << endl;
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