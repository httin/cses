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
int p[maxN];
int main() {
	cin.tie(0)->sync_with_stdio(0);
    //        0 1 2 3 4 5 6 7 8
    //        |               |
    // add 3: |     |         | output 5
    // add 6: |     |     |   | output 3
    // add 2: |   | |     |   | output 3
    int x,n;
    cin >> x >> n;
    map<int,int> mp; // count distance
    mp[x] = 1;
    set<int> s; // store traffic light's position
    s.insert(0);
    s.insert(x);
    for (int i = 0; i < n; i++) {
        cin >> p[i]; // Each position is distinct
        auto it = s.ub(p[i]);
        int r = *it;
        --it;
        int l = *it;
        s.insert(p[i]);
        --mp[r-l];
        if (mp[r-l]==0)
            mp.erase(r-l);
        mp[r - p[i]]++;
        mp[p[i] - l]++;
        auto maxDistance = mp.rbegin();
        cout << maxDistance->first << ' ';
    }
    return 0;
}
