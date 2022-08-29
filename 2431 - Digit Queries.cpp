#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
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
#define vvll        vector<vll>
#define mll         map<ll,ll>
#define test        ll T;cin>>T;while(T--)
#define ad(a,n)     vll a;a.resize(n);for(ll i=0;i<n;i++)cin>>a[i];
#define as(a,n)     for(ll i=0;i<n;i++){cout<<a[i]<<" ";}cout<<endl;
#define all(x)      x.begin(),x.end()

//typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;

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

ll fn(ll x, ll sz)
{
    ll cnt = 0;
    for (ll i = 0; i < sz; i++)
    {
        ll num = 9ll * pow(10, i - 1);
        cnt += num * i;
    }
    ll y = pow(10ll, sz - 1);
    cnt += ((x - y) * sz) + 1;
    return cnt;
}

int32_t main()
{
	ss99();
	test
	{
		ll n; cin >> n;
		ll len = 0, sum = 0;
		for (ll i = 0; i < 18; i++)
		{
			ll cur = 9ll * (i + 1) * pow(10ll, i);
			sum += cur;
			if (sum >= n)
			{
				len = i + 1;
				break;
			}
		}
		ll lo = pow(10ll, len - 1);
		ll hi = pow(10ll, len) - 1;
		ll ans = 0, ind = 0;
		while (lo <= hi)
		{
			ll mid = (lo + hi) / 2;
			ll cnt = fn(mid, len);
			if (cnt <= n)
			{
				ind = max(ind, cnt);
				ans = max(ans, mid);
				lo = mid + 1;
			}
			else
			{
				hi = mid - 1;
			}
		}
		cout << to_string(ans)[n - ind] << endl;
	}
	return 0;
}









