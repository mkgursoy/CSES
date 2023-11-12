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
void solve()
{
   	int n,a1,b1;
   	cin >> n >> a1 >> b1;
   	set<ar<int,2>> s;
   	int a[n+1];
   	int ans = mnn;
   	a[0] = 0;
   	for(int i = 0;n > i;i++)
   	{
   		int x;
   		cin >> x;
   		a[i+1] = x + a[i];
   	}

   	for(int i = a1;n >= i;i++)
   	{
   		s.insert({a[i-a1],i-a1});

   		if(i > b1)
   		{
   			s.erase(s.find({a[i-b1-1],i-b1-1}));
   		}

   		if(s.size()) ans = max(ans,a[i] - (*s.begin())[0]);
   		//cout << ans << endl;
   	}
   	cout << ans << endl;
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