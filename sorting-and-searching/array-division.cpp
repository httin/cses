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
int x[maxN];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n, k, Max = INT_MIN;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x[i], Max=max(Max, x[i]);
    }
    ll lo = Max, hi = 2*1e14;
    while (lo <= hi) {
        ll mi = lo + (hi - lo)/2;
        ll kneed = 0, s = 0;
        for (int i = 0; i < n; i++) {
            s += x[i];
            if (s > mi) {
                s = x[i];
                kneed++;
            }
        }
        
        if (kneed < k) {
            hi = mi - 1;
        } else {
            lo = mi + 1;
        }
    }
    cout << lo;
    return 0;
}
