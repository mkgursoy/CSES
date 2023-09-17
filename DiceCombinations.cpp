/*
    Author:Matkap(prefixsumenjoyer23)
    
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("O3,fast-math,inline")
#include <bits/stdc++.h>

using namespace std;
#define fr freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);


#define int long long
#define endl "\n"
const int mod = 1e9+7;
#define all(x) x.begin(),x.end()

int mxn = 1e18;
int mnn = -mxn;

void outarr(int ans[],int n)
{
	for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}
int binpow(int base,int power)
{
	if(power == 1) return base%mod;
	if(power == 0) return 1;
    
     if(power%2 == 1)
     {
     	 int a;
     	a = binpow(base,(power-1)/2);
     	return (a%mod*a%mod*base)%mod;
     } 
     else
     {
     	 int a;
     	a = binpow(base,power/2);
     	return a%mod*a%mod;
     } 

}
int gcd(int a, int b)
{

    if(b == 0) {
            return a;
    }
    else {
        return gcd(b, a % b);
    }
}
int lcm(int a,int b)
{
	return (a*b)/gcd(a,b);
}

void solve()
{
   	int n;
   	cin >> n;
   	int dp[n+1];

   	
   
   	for(int i = 1;n>=i;i++)
   	{
   		dp[i] = 1;
   		for(int j = 1;i > j;j++) dp[i] += dp[j],dp[i]%=mod;
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


//template




