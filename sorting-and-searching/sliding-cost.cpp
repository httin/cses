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
int x[maxN];

void solve2() {
    ordered_set<array<int,2>> os;
    ll cost = 0;
    int n,k,median;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> x[i];

    for (int i = 1; i <= k; i++) {
        os.insert({x[i],i});
    }
    median = (*os.find_by_order((k-1)/2))[0];
    for (int i = 1; i <= k; i++)
        cost += abs(x[i] - median);
    
    for (int i = k+1; i <= n; i++) {
        cost -= abs(median - x[i-k]);
        os.erase({x[i-k], i-k});
        os.insert({x[i], i});
        median = (*os.find_by_order((k-1)/2))[0];
        //...
    }
}

void solve() {
    int n,k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> x[i];

    if (k == 1) {
        for (int i = 0; i < n; i++) 
            cout << "0 ";
        return;
    }
    if (k == 2) {
        for (int i = 0; i < n-1; i++) 
            cout << abs(x[i] - x[i+1]) << ' ';
        return;
    }
    vector<array<int,2>> copy(k);
    for (int i = 0; i < k; i++)
        copy[i] = {x[i], i};
    sort(copy.begin(), copy.end());
    
    int median = copy[(k-1)/2][0];
    ll cost = 0, leftSum = 0, rightSum = 0;
    set<array<int,2>> left;
    set<array<int,2>> right;
    for (int i = 0; i < (k+1)/2; i++) {
        left.insert({copy[i]});
        leftSum += copy[i][0];
    }
    for (int i = (k+1)/2; i < k; i++) {
        right.insert({copy[i]});
        rightSum += copy[i][0];
    }
    
    cost = (left.size()*median - leftSum) + (rightSum - right.size()*median);
    cout << cost << ' ';
    //cout << "ls="<<leftSum<<" rs="<<rightSum<<" med="<<median<<endl;
    for (int i = k; i < n; i++) {
        if (left.count({x[i-k], i-k})) {
            leftSum -= x[i-k];
            left.erase({x[i-k], i-k});
        } else if (right.count({x[i-k], i-k})) {
            rightSum -= x[i-k];
            right.erase({x[i-k], i-k});
        }
        
        if ((*left.rbegin())[0] > x[i]) {
            left.insert({x[i], i});
            leftSum += x[i];
        } else {
            right.insert({x[i], i});
            rightSum += x[i];
        }
        
        // maintain left set always contain (k+1)/2 elements
        while (left.size() > (size_t)(k+1)/2) {
            array<int,2> move = (*left.rbegin());
            left.erase(move);
            right.insert(move);
            leftSum -= move[0];
            rightSum += move[0];
        }
        
        while (left.size() < (size_t)(k+1)/2) {
            array<int,2> move = (*right.begin());
            right.erase(move);
            left.insert(move);
            rightSum -= move[0];
            leftSum += move[0];
        }
        median = (*left.rbegin())[0];
        cost = (left.size()*median - leftSum) + (rightSum - right.size()*median);
        cout << cost << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
