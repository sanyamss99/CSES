#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define ll          long long
#define p7          1000000007
#define p9          998244353
#define pb          push_back
#define ff          first
#define ss          second
#define vll         vector<ll>
#define pll         pair<ll,ll>
#define vpll        vector<pll>
#define mll         map<ll,ll>
#define test        ll T;cin>>T;while(T--)
#define ad(a,n)     vll a;a.resize(n);for(ll i=0;i<n;i++)cin>>a[i];
#define as(a,n)     for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;
#define all(x)      x.begin(),x.end()
 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
ll powm(ll x, ll y, ll m = p7) {
	x = x % m; ll res = 1; while (y)
	{if (y & 1)res = res * x; res %= m; y = y >> 1; x = x * x; x %= m;} return res;
}
ll modi(ll a, ll m = p7) {return powm(a, m - 2, m);}
void yesno(bool f) {f ? cout << "YES" << endl : cout << "NO" << endl;}
 
 
void ss99()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}
 
bool f(vll& b, ll i, ll j, ll k)
{
	return (b[i] <= b[j] && b[j] > k);
}
 
 
int32_t main()
{
	ss99();
//	test
	{
		ll n, m; cin >> n >> m;
		ad(a, n);
		vpll vp(n);
		vll ind(n + 1);
		for (ll i = 0; i < n; i++)
		{
			ind[a[i]] = i;
			vp[i] = {a[i], i};
		}
		sort(all(vp));
		ll ans = 1;
		for (ll i = 1; i < n; i++)
			ans += (vp[i].ss < vp[i - 1].ss);
		while (m--)
		{
			ll x, y; cin >> x >> y;
			x--; y--;
			int r = a[x], s = a[y];
			swap(a[x], a[y]);
			if (ind[r - 1] <= ind[r] && ind[r - 1] > y) ans++;
			if (ind[r - 1] > ind[r] && ind[r - 1] <= y) ans--;
			if (ind[r] <= ind[r + 1] && y > ind[r + 1]) ans++;
			if (ind[r] > ind[r + 1] && y <= ind[r + 1]) ans--;
			ind[r] = y;
			if (ind[s - 1] <= ind[s] && ind[s - 1] > x) ans++;
			if (ind[s - 1] > ind[s] && ind[s - 1] <= x) ans--;
			if (ind[s] <= ind[s + 1] && x > ind[s + 1]) ans++;
			if (ind[s] > ind[s + 1] && x <= ind[s + 1]) ans--;
			ind[s] = x;
			cout << ans << endl;
		}
	}
	return 0;
}
