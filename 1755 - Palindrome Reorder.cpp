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

int32_t main()
{
	ss99();
	// test
	{
		string s; cin >> s;
		ll n = s.size();
		vll cnt(256, 0);
		for (ll i = 0; i < n; i++)
		{
			cnt[s[i]]++;
		}
		ll oc = 0;
		for (char c = 'A'; c <= 'Z'; c++)
		{
			oc += cnt[c] % 2;
		}
		if (oc != n % 2)
		{
			cout << "NO SOLUTION" << endl;
			return 0;
		}
		ll l = 0, r = n - 1;
		char x = '_';
		for (char c = 'A'; c <= 'Z'; c++)
		{
			if (cnt[c] % 2 == 0)
			{
				while (cnt[c] > 0)
				{
					s[l++] = s[r--] = c;
					cnt[c]-=2;
				}
			}
			else x = c;
		}
		if (x != '_')
		{
			while (l<=r)
			{
				s[l++] = s[r--] = x;
			}
		}
		cout << s << endl;
	}
	return 0;
}






