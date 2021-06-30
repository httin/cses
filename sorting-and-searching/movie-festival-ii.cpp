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
array<int,2> t[maxN];
int main() {
    cin.tie(0)->sync_with_stdio(0);
    // n=5 k=2
    // 1 2 3 4 5 6 7 8 9 10
    // |---1---|
    //   |--2--|
    //     -------
    //           |--1--|
    //               |--2-|
    int n,k,ans=0;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> t[i][0] >> t[i][1];
    }
    sort(t, t+n, [](const array<int,2>& a, const array<int,2>& b) -> bool {
        return a[1] < b[1];
    });
    //for(int i = 0; i < n; i++)
        //cout<<"("<<t[i][0]<<","<<t[i][1]<<")"<<endl;
    set<array<ll,2>> s;
    for (int i = 0; i < n; i++) {
        if (!s.empty() && t[i][0] >= (*s.begin())[0]) {
            auto it = s.ub({t[i][0], 0});
            --it;
            s.erase(it);
            s.insert({t[i][1], i});
            ans++;
            //cout<<t[i][0]<<" - "<<t[i][1]<<" size="<<s.size()<<" ans="<<ans<<endl;
            continue;
        }
        if (s.size() < (size_t)k) {
            s.insert({t[i][1], i});
            ans++;
        }
    }
    cout << ans;
    return 0;
}
