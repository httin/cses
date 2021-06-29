#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
 
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vpii = vector<pii>;
 
#define sz(x) int((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define pb push_back
#define eb emplace_back 
#define pf push_front
#define lb lower_bound
#define ub upper_bound
  
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define ROF(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define each(a,x) for (auto& a: x)
 
const int dr[4] = {1,0,-1,0};
const int dc[4] = {0,1,0,-1};
const int MOD = 1e9+7;
const ll INF = 1e18; // not too close to LLONG_MAX
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
template<typename T> using ordered_set = 
tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

const int maxN = 200000;
ll x[maxN + 1];
ll pref[maxN + 1];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    //          8 3 5
    //          -1 3 -2  5 3 -5 2 2
    // pref:  0 -1 2  0  5 8  3 5 7
    //           ^    |    |
    //             ^     |    |
    //                ^    |    |
    int n,a,b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        pref[i] = pref[i-1] + x[i];
    }
    
    set<array<ll,2>> s;
    for (int i = a; i <= b; i++)
        s.insert({pref[i], i});
    ll ans = (*s.rbegin())[0] - pref[0];
    
    for (int i = 2; i <= n - a + 1; i++) {
        if (i + b - 1 <= n)
            s.insert({pref[i+b-1], i+b-1});
        s.erase({pref[i+a-2], i+a-2});
        //cout<<"i="<<i<<" l="<<i+a-2<<" r="<<i+b-1<<endl;
        ans = max(ans, (*s.rbegin())[0] - pref[i-1]);
    }
    cout << ans;
    return 0;
}
