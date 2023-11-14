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
int INF = 1e16;

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
const int mxN = 21;
ar<int,2> dp[1 << mxN];
void solve()
{
   	int n,m;
   	cin >> n >> m;
   	int a[n];
   	for(int i = 0;n > i;i++) cin >> a[i];
   	for(int i = 0;(1 << mxN) > i;i++) dp[i] = {INF,INF};

   	dp[0] = {1,0};

   	for(int i = 1;(1 << n) > i;i++)
   	{
   		for(int j = 0;n > j;j++)
   		{
   			if((1 << j) & i)
   			{
   				ar<int,2> prev = dp[(1 << j) ^ i];
   				int cnt = prev[0];
   				int weight = prev[1];

   				if(m >= a[j] + weight) weight += a[j];
   				else
   					weight = a[j] , cnt += 1;

   				dp[i] = min(dp[i],{cnt,weight});
   			}
   		}
   	}
   	cout << dp[(1 << n) - 1][0] << endl;
}



int32_t main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

//	fr

	int t;
	t=1;
	//cin >> t;
	while(t--) solve();

}