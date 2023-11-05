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
  	int n;
  	cin >> n;
  	ar<int,3> a[n];
  	int ans[n];
  	int cur = 1;
  	multiset<ar<int,3>> ms;
  	for(int i = 0;n > i;i++) cin >> a[i][0] >> a[i][1],a[i][2] = i,ms.insert({a[i][0],a[i][2],a[i][1]});
  	memset(ans,-1,sizeof(ans));
  	sort(a,a+n);
  	for(int i = 0;n > i;i++)
  	{
  		if(ans[a[i][2]] == -1)
  		{
  			ans[a[i][2]] = cur;
  			auto h = ms.upper_bound({a[i][1]+1,0});

  			while(h != ms.end())
  			{
  				
  				array<int,3> k = *h;
  				ans[k[1]] = cur;
  				ms.erase(h);
  				h = ms.upper_bound({k[2]+1,0});
  			}
  			
  			cur++;
  		}


  	}
  	cout << cur-1 << endl;
  	for(auto it : ans) cout << it << " ";



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