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

ll path[48] = {0};
ll dx[4] = {-1,0,0,1};
ll dy[4] = {0,-1,1,0};
bool vis[7][7];

 
void solve(int i, int j, ll step, ll& ans)
{
    //raasta mil gaya
    if(i == 6 and j == 0)
    {
        if(step == 48) ans++;
        return;
    }
    
    // hitting left wall perpendicular
    if(j==0 and i>0 and i<6 and !vis[i-1][j] and !vis[i+1][j]) return;
    // hitting right wall perpendicular
    if(j==6 and i>0 and i<6 and !vis[i-1][j] and !vis[i+1][j]) return;
    // hitting roof perpendicular
    if(i==0 and j>0 and j<6 and !vis[i][j-1] and !vis[i][j+1]) return;
    // hitting floor perpendicular
    if(i==6 and j>0 and j<6 and !vis[i][j-1] and !vis[i][j+1]) return;
    
    if(i>0 and i<6 and j>0 and j<6)
    {
        if(vis[i-1][j] and vis[i+1][j] and !vis[i][j-1] and !vis[i][j+1])
            return;
        if(!vis[i-1][j] and !vis[i+1][j] and vis[i][j-1] and vis[i][j+1])
            return;
    }
    
    
    vis[i][j] = true;
    
    // agar fixed character hai to us direction mein jaane ka
    if(path[step] != -1)
    {
        ll u = i + dx[path[step]], v = j + dy[path[step]];
        if(u>=0 and u<7 and v>=0 and v<7 and !vis[u][v])
        {
            solve(u,v,step+1,ans);
        }
        vis[i][j] = false;
        return;
    }
    
    // chaaro dishao mein jaane ka
    for(ll k=0; k<4; k++)
    {
        ll u = i + dx[k], v = j + dy[k];
        if(u<0 or u>6 or v<0 or v>6 or vis[u][v])
            continue;
        solve(u,v,step+1,ans);
    }
    vis[i][j] = false;
}
 
int32_t main()
{
	ss99();
	//test
	{
	    memset(vis,false,sizeof(vis));
	    string s; cin>>s;
	    map<char,int> mp;
	    mp['?'] = -1; mp['U'] = 0; mp['L'] = 1; mp['R'] = 2; mp['D'] = 3;
	    for(ll i=0; i<48; i++)
	        path[i] = mp[s[i]];
		vis[0][0] = true;
		ll ans = 0;
		solve(0,0,0,ans);
		cout<<ans<<endl;
	}
	return 0;
}
 
 
 
 
 
 
 
 
 
