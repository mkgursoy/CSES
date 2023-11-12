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
const int mxN = 10e6 + 5;
int dp[mxN];
vector<int> findDigit(int x)
{
	vector<int> ans;

	while(x != 0)
	{
		ans.push_back(x%10);
		x/=10;
	}
	return ans;
}
void solve()
{
   	int n;
   	cin >> n;
   	dp[0] = 0;
   	for(int i = 1;n >= i;i++)
   	{
   		dp[i] = mxn;
   		vector<int> digits = findDigit(i);

   		for(auto it : digits)
   		{  			
   			dp[i] = min(dp[i],dp[i - it] + 1); 
   		}
   		//cout << i << ": " << dp[i] << endl;
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