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
const int mxX = 1e5 + 5,mxN = 1e3 + 5;
int dp[mxX];
int val[mxN];
int weight[mxN];
void solve()
{
   	int n,m;
   	cin >> n >> m;
   	for(int i = 0;n > i;i++) cin >> weight[i];
   	for(int i = 0;n > i;i++) cin >> val[i];

   	for(int i = 1;n >= i;i++)
   	{
   		for(int j = m;j >= weight[i-1];j--)
   		{
   			dp[j] = max({dp[j-1],dp[j],dp[j-weight[i-1]] + val[i-1]});
   		}
   	}
   
   	cout << dp[m] << endl;
}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	//fr

	int t;
	t=1;
//	cin >> t;
	while(t--) solve();

}