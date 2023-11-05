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
   	int n,q;
   	cin >> n >> q;

   	set<int> st;
   	multiset<int> ans;
   	st.insert(0);
   	st.insert(n);
   	ans.insert(n);
   	while(q--)
   	{
   		int x;
   		cin >> x;
   		auto it = st.upper_bound(x);

   		int r = *it;
   		int l = *(--it);

   		ans.erase(ans.find(r-l));
   		ans.insert(x-l);
   		ans.insert(r-x);
   		st.insert(x);
   		cout << *(--ans.end()) << endl;
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