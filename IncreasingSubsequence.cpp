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
   	//Non - DP solution lol
  	int n;
  	cin >> n;
  	vector<int> lis;
  	for(int i = 0;n > i;i++)
  	{
  		int x;
  		cin >> x;
  		auto h = upper_bound(all(lis),x-1);

  		if(h == lis.end()) lis.push_back(x);
  		else
  		{ 			
  			int h1 = h - lis.begin();
  			lis[h1] = x;
  		}
  	}
  	cout << lis.size() << endl;
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