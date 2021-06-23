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
	int n;
	cin >> n;
	cout << "0\n";
	// number of ways to put two knights on an nxn chessboard
	// 	               C(2,n^2) = n^2(n^2 - 1)/2
    // number of ways to put two knights so they do attack each other
    // is number of 2x3 or 3x2 rectangle, and there are two ways to 
    // place the knights in each rectangle
    //            2*((n - 1)(n - 2) + (n - 2)(n - 1))
	for (int k = 2; k <= n; k++) {
		ll k2 = k*k;
        cout << k2*(k2 - 1)/2 - 4*(k - 1)*(k - 2) << '\n';
	}
	return 0;
}