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

const int maxN = 200000;
pii t[maxN];
int main() {
	cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    // 3-5
    // 3--6
    //  4-6  
    //    67
    //   5--8
    //     78
    //      89
    //      8-10
    //
    // 1 2 3 4 5 6 7 8 9 10
    //     |---|
    //     -------
    //       -----      
    //           |-|    
    //         -------
    //             |-|  
    //               |-|
    //               -----
    for (int i = 0; i < n; i++) {
        cin >> t[i].first >> t[i].second;
    }
    
    sort(t, t+n, [](const pii& t1, const pii& t2) -> bool {
        return t1.second < t2.second;
    });
    
    int ans = 0, start = 0;
    for (int i = 0; i < n; i++) {
        //cout << "start="<<t[i].first<<"\tend="<<t[i].second<<endl;
        if (t[i].first >= start) {
            ans++;
            start = t[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}
