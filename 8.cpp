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
	ll sum = 1LL*n*(n + 1)/2;
    if (sum%2)
        cout << "NO\n";
    else {
        cout << "YES\n";
        ll sum1 = sum/2;
        vi v1,v2;
        for (int i = n; i >= 1; i--) {
            if (sum1 >= i) {
                v1.pb(i);
                sum1 -= i;
            } else {
                v2.pb(i);
            }
        }
        
        cout << v1.size() << '\n';
        for (auto& j : v1)
            cout << j << ' ';
        cout << '\n' << v2.size() << '\n';
        for (auto& j : v2)
            cout << j << ' ';
        cout << endl;
    }
    return 0;
}
