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

template <typename T>
void DEBUG(T&& t) {cout << t << "\n";}
 
template <typename T, typename... Args>
void DEBUG(T&& t, Args&&... args) 
{
    cout << t << " ";
    DEBUG(forward<Args>(args)...);
}
 

const int maxN = 200000;
array<int,2> ans[maxN];
array<int,3> ranges[maxN];
int main() {
	cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    // 1 2 3 4 5 6 7 8
    // -----------
    //   -------
    //   -----
    //     -------
    //     ---
    //       ---------
    for (int i = 0; i < n; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
        ranges[i][2] = i;
    }
    sort(ranges, ranges+n, [](const array<int,3>& a, const array<int,3>& b) -> bool {
        if (a[0] != b[0])
            return a[0] < b[0];
        return a[1] > b[1];
    });
    int end = ranges[0][1];
    for (int i = 1; i < n; i++) {
        if (ranges[i][1] <= end) {
            ans[ranges[i][2]][1] = 1;
        }
        end = max(end, ranges[i][1]);
        //cout<<"l=" << ranges[i][0] << " r=" << ranges[i][1] << endl;
    }
    
    sort(ranges, ranges+n, [](const array<int,3>& a, const array<int,3>& b) -> bool {
        if (a[1] != b[1])
            return a[1] < b[1];
        return a[0] > b[0];
    });
    
    int start = ranges[0][0];
    for (int i = 1; i < n; i++) {
        if (ranges[i][0] <= start) {
            ans[ranges[i][2]][0] = 1;
        }
        start = max(start, ranges[i][0]);
        //cout<<"l=" << ranges[i][0] << " r=" << ranges[i][1] << endl;
    }
    
    for (int i = 0; i < n; i++)
        cout << ans[i][0] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++)
        cout << ans[i][1] << ' ';
    cout << endl;
    return 0;
}
