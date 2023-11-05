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
bool comp(ar<int,3> a,ar<int,3> b)
{
	if(a[0] ^ b[0]) return a[0] < b[0];
	else
		return a[1] > b[1];
}
void solve()
{
   	int n;
   	cin >> n;
   	ar<int,3> a[n];
   	int ans[2][n];
   	for(int i = 0;n > i;i++) cin >> a[i][0] >> a[i][1],a[i][2] = i;

   	sort(a,a+n,comp);
   

   	int mnr = a[n-1][1];
   	ans[0][a[n-1][2]] = 0;
   	for(int i = n-2;i >= 0;i--)
   	{
   		if(a[i][1] >= mnr)
   		{
   			ans[0][a[i][2]] = 1;
   		}
   		else
   			ans[0][a[i][2]] = 0;
   		mnr = min(mnr,a[i][1]);
   	}
   	
   	

   	int mxr = a[0][1];

   	ans[1][a[0][2]] = 0;
   	for(int i = 1;n > i;i++)
   	{
   		if(mxr >= a[i][1]) ans[1][a[i][2]] = 1;
   		else
   			ans[1][a[i][2]] = 0;

   		mxr = max(a[i][1],mxr);
   	}
   	for(int k = 0;2 > k;k++)
   	{
   		for(int i = 0;n > i;i++) cout << ans[k][i] << " ";
   		cout << endl;
   	}
   	
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