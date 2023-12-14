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

int INF = 1e18;

void setIO(string name = "") 
{
	if (name.size())
	{
		freopen((name + ".in").c_str(), "r", stdin); // see /general/input-output
		freopen((name + ".out").c_str(), "w", stdout);
	}
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
const int mxN = 2e5 + 7;
int hotel[mxN] , group[mxN];
int n,m;
int tree[4 * mxN];
void build(int pos,int l,int r)
{
	if(l > r) return;
	if(l == r)
	{
		tree[pos] = hotel[l-1];
		return;
	}
	int mid = (l+r)/2;
	build(pos * 2,l,mid);
	build(pos * 2 + 1,mid+1,r);
	tree[pos] = max(tree[pos*2],tree[pos*2+1]);
}
void ans(int x,int pos,int l,int r)
{
	if(l > r) return;
	if(l == r)
	{
		cout << l << " ";
		cout << endl;
		tree[pos] -= x;
		return;
	} 
	int mid = (l+r)/2;
	//cout << x << " " << tree[pos*2] << " " << tree[pos*2+1] << endl;
	if(tree[pos*2] >= x) ans(x,pos*2,l,mid);
	else
		ans(x,pos*2+1,mid+1,r);
	tree[pos] = max(tree[pos*2] , tree[pos*2+1]);
}
void solve()
{
	cin >> n >> m;
	for(int i = 0;n > i;i++) cin >> hotel[i];
	for(int i = 0;m > i;i++) cin >> group[i];
	build(1,1,n);
	
	for(int i = 0;m > i;i++)
	{
		if(tree[1] < group[i]) cout << "0" << endl;
		else
			ans(group[i] , 1 , 1 ,n);
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