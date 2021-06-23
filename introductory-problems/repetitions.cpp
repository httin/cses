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

// re(a,b,c,...) reads vectors, arrays of pairs, complex, etc
// pr(a,b,c,...) prints with no spaces. ps(a,b,c,...) prints with space and \n.
// All outputs uses ts() to generate string. vectors, bitsets, pairs, OK
// dbg() debugs stuff. dbgl() debugs stuff with level.
 
int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
	cin >> s;
	int ans = 0, cur = 0;
	char ch = s[0];
	for (auto& c : s) {
		if (c == ch) {
			cur++;
		} else {
			ch = c;
			cur = 1;
		}
		ans = max(ans, cur);
	}
	cout << ans;
	return 0;
}
