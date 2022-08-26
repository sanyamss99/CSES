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
 
vector<string> board(8);
ll ans = 0;
vll ld(15, 0), rd(15, 0), rw(8, 0);
 
void solve(ll j)
{
    if (j == 8)
    {
        ans++;
        return;
    }
    for (ll i = 0; i < 8; i++)
    {
        if (board[i][j] == '.' && ld[i - j + 7] == 0 && rd[i + j] == 0 && rw[i] == 0)
        {
            ld[i - j + 7] = 1; rd[i + j] = 1; rw[i] = 1;
            solve(j + 1);
            ld[i - j + 7] = 0; rd[i + j] = 0; rw[i] = 0;
        }
    }
}
 
 
 
 
int32_t main()
{
    ss99();
//    test
    {
        for (ll i = 0; i < 8; i++)
            cin >> board[i];
        solve(0);
        cout << ans << endl;
    }
    return 0;
}
