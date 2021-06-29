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
void solve2() {
    array<int,3> a[maxN]; // {end,start,id}
    int n, ans[maxN];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i][1] >> a[i][0];
        a[i][2] = i;
    }
    // 1:  23      {[3,1]}
    // 2: 1--4     {[3,1],[4,2]}
    // 3:  2-4     {[3,1],[4,2],[4,3]}
    // 4:   3-5    {[3,1],[4,2],[4,3],[5,4]}
    // 5:    4-6   {[4,2],[4,3],[5,4],[6,1]}
    // 6:     5-7  {[4,3],[5,4],[6,1],[7,2]}
    sort(a, a+n); // end-time ascending
    set<array<int,2>> s; // {end, room-id}
    for (int i = 0; i < n; i++) {
        auto it = s.lb({a[i][1]});
        if (it != s.begin()) { // depart
            --it; // should be s.begin()
            ans[a[i][2]] = (*it)[1];
            s.erase(it);
        } else { // arrive
            ans[a[i][2]] = s.size()+1;
        }
        s.insert({a[i][0], ans[a[i][2]]});
    }
    cout << s.size() << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
    cout << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    // 1  4  2------9
    //  23     4--7  
    //  2-4    4----9
    //   3-5     6-----11
    //    4-6      8------13
    //     5-7       10------15
    set<array<int,2>> customer;
    for (int i = 1; i <= n; i++) {
        int a,b;
        cin >> a >> b;
        customer.insert({2*a, i});
        customer.insert({2*b+1, i});
    }
    int ans = 0, k = 0;
    vector<int> rans(n+1);
    map<int,int> mp;
    queue<int> roomq;
    for (auto& c : customer) {
        if (c[0]%2 == 0) { // arrive
            k += 1;
            if (roomq.empty()) {
                mp[c[1]] = k;
                rans[c[1]] = k;
            } else {
                int room = roomq.front();
                roomq.pop();
                mp[c[1]] = room;
                rans[c[1]] = room;
            }
        } else { // depart
            k -= 1;
            roomq.push(mp[c[1]]);
            mp.erase(c[1]);
        }
        ans = max(ans, k);
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        cout << rans[i] << ' ';
    cout << endl;
    return 0;
}
