/*
    Author:Matkap(prefixsumenjoyer23)
    
*/

#include <bits/stdc++.h>
#include <array>

using namespace std;

#define fr freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);
#define int long long
#define endl "\n"
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
   vector<array<int,2>> vec;

   for(int i = 0;n > i;i++)
   {
   		int x,y;
   		cin >> x >> y;
   		vec.push_back({x,1});
   		vec.push_back({y,-1});
   }
   sort(all(vec));
   int ppl = 0,mxppl = 0;
   for(auto it : vec)
   {
   		ppl += it[1];
   		mxppl = max(mxppl,ppl);
   }

   cout << mxppl << endl;




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