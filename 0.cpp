#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vpii = vector<pii>;
 
#define tcT template<class T
#define tcTU tcT, class U
template<class T> using V = vector<T>;
 
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
 
tcT> int lwb(V<T>& a, const T& b) { return int(lb(all(a),b)-bg(a)); }
 
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
 
constexpr int pct(int x) { return __builtin_popcount(x); } // # of bits set
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }
ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down
tcT> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
tcT> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
tcTU> T fstTrue(T lo, T hi, U f) { hi ++; assert(lo <= hi); while (lo < hi) { T mid = lo+(hi-lo)/2; f(mid) ? hi = mid : lo = mid+1; } return lo; }
tcTU> T lstTrue(T lo, T hi, U f) { lo --; assert(lo <= hi); while (lo < hi) { T mid = lo+(hi-lo+1)/2; f(mid) ? lo = mid : hi = mid-1; } return lo; }
tcT> void remDup(vector<T>& v) { sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void erase(T& t, const U& u) { auto it = t.find(u); assert(it != end(t)); t.erase(it); } 
#define tcTUU tcT, class ...U
#ifdef LOCAL
	#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
	#define dbgl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
#else 
	#define dbg(...) 0
	#define dbgl(lev,x) 0
#endif
void decrement() {} // subtract one from each
tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
#define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
#define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
 
// re(a,b,c,...) reads vectors, arrays of pairs, complex, etc
// pr(a,b,c,...) prints with no spaces. ps(a,b,c,...) prints with space and \n.
// All outputs uses ts() to generate string. vectors, bitsets, pairs, OK
// dbg() debugs stuff. dbgl() debugs stuff with level.
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	return 0;
}