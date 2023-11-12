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
 	int n,k;
 	cin >> n >> k;
 	set<ar<int,2>> st;
 	ar<int,3> a[n];
 	int vis[n];
 	int ans2 = 0;
 	int ans[n];
 	memset(vis,0,sizeof(vis));
 	int cur = 0,cnt = 0;
 	for(int i = 0;n > i;i++)
 	{
 		cin >> a[i][1] >> a[i][0];
 		a[i][2] = i;		
 	}
 	sort(a,a+n);
 	for(int i = 0;n > i;i++)
 	{
 		auto h = st.lower_bound({a[i][1] + 1,0});

 		if(h != st.begin())
 		{
 			--h;
 			ans[a[i][2]] = (*h)[1];
 			st.erase(h);
 			

 		}
 		else
 		{
 			ans[a[i][2]] = st.size();
 		}		
 			

 		if(k > st.size())
 		{
 			st.insert({a[i][0],a[i][2]});
 			ans2 += 1;
 		}
 			


 		//cout << st.size() << " " << ans2 << endl;
	}
	cout << ans2 << endl;
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