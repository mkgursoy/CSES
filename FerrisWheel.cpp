/*
    Author:Matkap(prefixsumenjoyer23)
    
*/

#include <bits/stdc++.h>

using namespace std;
#define fr freopen("/Users/metinkasim/Documents/in.txt","r",stdin);freopen("/Users/metinkasim/Documents/out.txt","w",stdout);


#define int long long
#define endl "\n"
#define mod  998244353
#define all(x) x.begin(),x.end()

int mxn = 1e18;
int mnn = -mxn;

void outarr(int ans[],int n)
{
	for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}
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
   	int n,m;
   	cin >> n >> m;
   	int ar[n];
   	for(int i = 0;n > i;i++)
   	{
   		cin >> ar[i];
   	}
   	sort(ar,ar+n);
   	int ans = 0;
   	int l = 0,r = n-1;

   	while(r >= l)
   	{
   		if(ar[r] + ar[l] > m)
   		{
   			r--;
   			ans++;
   		}
   		else
   		{
   			r--;
   			l++;
   			ans++;
   		}
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


