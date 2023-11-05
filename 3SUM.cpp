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
   	int n,x;
   	cin >> n >> x;
   	ar<int,2> a[n];
   	for(int i = 0;n > i;i++)
   	{
   		cin >> a[i][0];
   		a[i][1] = i;
   	}
   	sort(a,a+n);
   	for(int i = 0;n - 2 > i;i++)
   	{
   		int l = i+1;
   		int r = n-1;
   		int new_x = x - a[i][0];

   		while(r > l)
   		{
   			if(a[r][0] + a[l][0] > new_x) r -= 1;
   			else if(a[r][0] + a[l][0] < new_x) l += 1;
   			else
   			{
   				cout << a[i][1]+1 << " " << a[l][1]+1 << " " << a[r][1]+1 << endl;
   				return;
   			}
   		}


   	}
   	cout << "IMPOSSIBLE" << endl;
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