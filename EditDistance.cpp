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
const int mxN = 5 * 1e3 + 5,mxM = 5 * 1e3 + 5;
int dp[mxN][mxM];
void solve()
{
   	string s1,s2;
   	cin >> s1 >> s2;
   	int n = s1.size();
   	int m = s2.size();

   	for(int i = 0;n >= i;i++)
   	{
   		for(int j = 0;m >= j;j++)
   		{
   			if(!(i == 0 && j == 0))
   			dp[i][j] = mxn;   			
   			if(i != 0) dp[i][j] = min(dp[i][j],dp[i-1][j] + 1);
   			if(j != 0) dp[i][j] = min(dp[i][j],dp[i][j-1] + 1);
   			if(i != 0 && j != 0) dp[i][j] = min(dp[i][j],dp[i-1][j-1] + (s1[i-1] != s2[j-1]));
   			
   			//cout << dp[i][j] << " ";
   		}
   		//cout << endl;	
   	}
   	cout << dp[n][m] << endl;
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