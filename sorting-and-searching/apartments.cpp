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
const int maxM = 200000;
int a[maxN];
int b[maxM];
int main() {
	cin.tie(0)->sync_with_stdio(0);
    int n, m, k, i = 0, j = 0, ans = 0;
    cin >> n >> m >> k;
    for (int t = 0; t < n; t++)
        cin >> a[t];
    for (int t = 0; t < m; t++)
        cin >> b[t];
    sort(a, a+n);
    sort(b, b+m);
    
    //for (int i = 0; i < n; i++)
        //cout << a[i] << ' ';
    //cout << endl;
    //for (int i = 0; i < m; i++)
        //cout << b[i] << ' ';
    //cout << endl;
    
    while (i < n && j < m) {
        if (b[j] - k <= a[i] && a[i] <= b[j] + k) {
            i++;
            j++;
            ans++;
        } else if (a[i] < b[j] - k) {
            i++;
        } else {
            j++;
        }
    }
    
    cout << ans;
    return 0;
}
