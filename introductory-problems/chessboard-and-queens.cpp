
#include <bits/stdc++.h>
using namespace std;
 
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

int main() {
	cin.tie(0)->sync_with_stdio(0);
    string board[8];
    for (int i = 0; i < 8; i++)
        cin >> board[i];
    int ans = 0;
    int p[8]; // place queen at (i,p[i])
    bool d[15]; // bitcheck diagonal
    std::iota(p, p+8, 0);
    do {
        bool ok = true;
        // make sure we can set up with this p[].
        for (int i = 0; i < 8; i++)
            ok &= board[i][p[i]]=='.';
        if (!ok) continue;
        // now consider queens could attack each other diagonally.
        memset(d, 0, 15);
        for (int i = 0; i < 8; i++) {
            if (d[i+p[i]])
                ok = 0;
            d[i+p[i]] = 1;
        }
        memset(d, 0, 15);
        for (int i = 0; i < 8; i++) {
            if (d[i+7-p[i]])
                ok = 0;
            d[i+7-p[i]] = 1;
        }
        ans += ok;
    } while (std::next_permutation(p, p+8));
    
    cout << ans;
    return 0;
}
