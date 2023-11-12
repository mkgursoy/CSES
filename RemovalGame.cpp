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
const int mxN = 5 * 1e3 + 5;
int dp[mxN][mxN];
void solve()
{
   	int n;
   	cin >> n;
   	int a[n];
   	for(int i = 0;n > i;i++) cin >> a[i];
   	for(int i = 0;n >= i;i++)
   	{
   		for(int j = i;n >= j;j++)
   		{
   			int new_i = j-i;
   			int pos_1 = 0,pos_2 = 0,pos_3 = 0;
   			if(new_i + 1 <= j-1)
   			pos_1 = dp[new_i+1][j-1];
   			if(new_i + 2 <= j)
   			pos_2 = dp[new_i+2][j];
   			if(new_i <= j-2)
   			pos_3 = dp[new_i][j-2];

   			//Choose i:
   			int l = a[new_i-1] + min(pos_1,pos_2);
   			//Choose j:
   			int r = a[j-1] + min(pos_1,pos_3);

   			dp[new_i][j] = max(l,r);
   			
   		}
   	}
   	cout << dp[1][n];
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