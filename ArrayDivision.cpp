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
   	int a[n];
   	for(int i = 0;n > i;i++) cin >> a[i];
   	int l = *max_element(a,a+n),r = (int)10e16;

   	while(r > l)
   	{
   		//cout << l << " " << r << endl;
   		int mid = (l+r)/2;
   		int num = 0;
   		int cur = 0;
   		for(int i = 0;n > i;i++)
   		{
   			if(cur + a[i] > mid)
   			{
   				cur = a[i];
   				num++;
   			}
   			else
   				cur += a[i];
   		}
   		num++;

   		if(num > k) l = mid+1;
   		else
   			r = mid;

   	}
   	cout << l << endl;
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