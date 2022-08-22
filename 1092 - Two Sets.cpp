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
	//freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

int32_t main()
{
	ss99();
	// test
	{
		ll n; cin >> n;
		ll sum = n * (n + 1) / 2;
		if (sum % 2 == 1)
		{
			yesno(0);
			return 0;
		}
		set<ll> st1, st2;
		sum /= 2;  
		for (ll i = n; i >= 1; i--)
		{
			if (i >= sum)
			{
				st1.insert(sum);
				break;
			}
			st1.insert(i);
			sum-=i;
		}
		for (ll i = n; i >= 1; i--)
		{
			if (st1.find(i) == st1.end())
			{
				st2.insert(i);
			}
		}
		yesno(1);
		cout << st1.size() << endl;
		for (auto it : st1)
			cout << it << " ";
		cout<<endl;
		cout << st2.size() << endl;
		for (auto it : st2)
			cout << it << " ";
		cout << endl;
	}
	return 0;
}
