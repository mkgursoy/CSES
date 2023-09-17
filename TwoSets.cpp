/*
    Author:Matkap(prefixsumenjoyer23)
    
*/
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("O3,fast-math,inline")
#include <bits/stdc++.h>

using namespace std;
#define fr freopen("in.txt","r",stdin);freopen("out.txt","w",stdout);
#define mxn 999999999
#define mnn -mxn
#define int long long
#define endl "\n"
#define mod  998244353
#define all(x) x.begin(),x.end()

void outarr(int ans[],int n)
{
	for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i == n - 1];
}
int binpow(int base,int power)
{
	if(power == 1) return base;
	if(power == 0) return 1;
    
     if(power&2)
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
   	
   	map<int,int> mp;

   	int n;
   	cin >> n;

   	int sum = ((n)*(n+1))/2;
   	sum/=2;

   	int k = 0;
   	for(int i = n;i>=1;i--)
   	{
   		if(sum-k <= i)
   		{
   			mp[sum-k] = 1;
   			break;

   		}

   		k += i;
   		mp[i] = 1;
   	}
   	vector<int> vec;
   	vector<int> vec1;
   	k = 0;
   	for(int i = 1;n>=i;i++)
   	{
   		//cout << i<< " " << mp[i] << endl;
   		if(mp[i] != 1) vec.push_back(i),k+= i;
   		else
   			vec1.push_back(i);

   		
   	}

   	if(k == sum)
   	{
   		cout << "YES" << endl;
   		cout << vec1.size() << endl;
   		for(auto it : vec1) cout << it<< " ";
   			cout << endl;
   			cout << vec.size() << endl;
   		for(auto it : vec) cout << it << " ";
   			return;
   	}
   cout << "NO" << endl;


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


//template




