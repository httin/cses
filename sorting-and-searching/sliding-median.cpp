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

const int maxN = 200001;
int x[maxN];

void solve() {
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    if (k == 1) {
        for (int i = 0; i < n; i++)
            cout << x[i] << ' ';
        return;
    }
    if (k == 2) {
        for (int i = 0; i < n-1; i++)
            cout << min(x[i], x[i+1]) << ' ';
        return;
    }
    vector<array<int,2>> copy(k);
    for (int i = 0; i < k; i++)
        copy[i] = {x[i],i};
    sort(copy.begin(), copy.end());
    set<array<int,2>> left;
    set<array<int,2>> right;
    for (int i = 0; i < (k+1)/2; i++)
        left.insert(copy[i]);
    for (int i = (k+1)/2; i < k; i++)
        right.insert(copy[i]);
    cout << (*left.rbegin())[0] << ' ';
    
    for (int i = k; i < n; i++) {
        if (left.count({x[i-k], i-k}))
            left.erase({x[i-k], i-k});
        else
            right.erase({x[i-k], i-k});
    
        array<int,2> cur = {x[i],i};
        if ((*left.rbegin())[0] < x[i])
            right.insert(cur);
        else
            left.insert(cur);
        
        // maintain left set to have exactly (k+1)/2 elements
        while (left.size() < (size_t)(k+1)/2) {
            array<int,2> move = (*right.begin());
            left.insert(move);
            right.erase(move);
        }
        while (left.size() > (size_t)(k+1)/2) {
            array<int,2> move = (*left.rbegin());
            left.erase(move);
            right.insert(move);
        }
        cout << (*left.rbegin())[0] << ' ';
    }
}

void solve2() {
    int n,k;
    cin >> n >> k;
    ordered_set<array<int,2>> os;
    for (int i = 1; i <= n; i++) {
        cin >> x[i];
        os.insert({x[i],i});
        if (os.size() > (size_t)k)
            os.erase({x[i - k], i - k});
        
        if (os.size() == (size_t)k) {
            auto it = os.find_by_order((k-1)/2);
            cout << (*it)[0] << ' ';
        }
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve2();
    return 0;
}


