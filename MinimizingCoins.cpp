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
int mxM = 1e6 + 5;
void solve()
{
   	int n,m;
   	cin >> n >> m;
   	int dp[mxM];	
   	int a[n];
   	for(int i = 0;n > i;i++) cin >> a[i];
   	sort(a,a+n);
   	dp[0] = 0;
   	for(int i = 1;m >= i;i++)
   	{	
   		dp[i] = mxn;	
   		for(int j = 0;n > j;j++)
   		{
   			if(i < a[j]) break;
   			dp[i] += min(1 + dp[i - a[j]],dp[i]);
   		}
   		//cout << dp[i] << " ";
   	}
   	if(dp[m] == mxn)
   	{
   		cout << "-1" << endl;
   	}
   	else
   	cout << dp[m] << endl;
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