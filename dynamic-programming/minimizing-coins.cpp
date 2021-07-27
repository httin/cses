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

const int maxN = 100;
int c[maxN];
int n, x;

int bfs() {
    int s=0;
    vector<bool> vis(x+1, 0);
    queue<pii> q;
    q.push(pii(s,0));
    vis[0]=1;
    while (!q.empty()) {
        s = q.front().first;
        int coins = q.front().second;
        q.pop();
        if (s==x)
            return coins;
        for (int i=0; i<n; i++) {
            int sum = s+c[i];
            if (sum <= x && !vis[sum]) {
                q.push(pii(sum, coins+1));
                vis[sum] = 1;
            }
        }
    }
    return -1;
}

int dynamic_programming() {
    vector<int> dp(x+1, 1e9);
    dp[0] = 0;
    for (int i=1; i<=x; i++) {
        for (int j=0; j<n; j++) {
            if (c[j] <= i)
                dp[i] = min(dp[i - c[j]] + 1, dp[i]);
        }
    }
    return dp[x] >= 1e9 ? -1 : dp[x];
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    // n=3: {2,5,7}, x=13
    // i : [ 1,2, 3,4,5,6,7,8,9,10,11,12,13]
    // dp:  -1 1 -1 2 1 3 1 4 2 2  3  2  4
    cin >> n >> x;
    for (int i=0; i<n; i++)
        cin >> c[i];
    //cout << bfs() << endl;
    cout << dynamic_programming() << endl;
    return 0;
}
