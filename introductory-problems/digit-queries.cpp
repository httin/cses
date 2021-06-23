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
    ll q, k;
    cin >> q;
    while(q--) {
        cin >> k;
        // 12...9| 10.11...99 | 100.101...999
        // ^    ^  ^  ^     ^   ^   ^
        // 1    9|10  12   189|190 193   
        ll dig = 1, lower = 1, upper = 0, i = 9, lo = 1, hi = 9, mi, _lo, x;
        while (upper < k)
        {
            lower = upper + 1; // 1 10 190 ...
            upper += i*dig; // 9*1 + 90*2 + 900*3 + ...
            dig++;   // 1 2  3   ...
            i *= 10; // 9 90 900 ...
        }
        --dig, i = 1;
        
        while (i++ < dig) {
            lo *= 10;
            hi = 10*hi + 9;
        }
        
        _lo = lo;
        while (lo <= hi) {
            mi = lo + (hi - lo)/2;
            x = lower + (mi - _lo)*dig;
            //cout<<"low="<<lo<<" high="<<hi<<" num="<<mi<<" x="<<x<<endl;
            if (x >= k - dig + 1 && x <= k)
                break;
            else if (x > k)
                hi = mi - 1;
            else
                lo = mi + 1;
        }
        
        string num = std::to_string(mi);
        cout << num[k - x] << endl;
    }
    return 0;
}
