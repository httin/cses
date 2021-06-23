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

int d[26];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s;
    cin >> s;
    for (char& c : s)
        d[c-'A']++;
    int odd = 0;
    for (int i = 0; i < 26; i++)
        odd += d[i]%2;
    if (odd > 1)
        cout << "NO SOLUTION";
    else {
        int i = 0, n = s.size(), k = n/2;
        for (int j = 0; j < 26; j++) {
            while (d[j] > 0) {
                if (d[j]%2==0) {
                    s[i] = s[n-i-1] = j + 'A';
                    i++;
                } else {
                    s[k-d[j]/2] = s[k+d[j]/2] = j + 'A';
                }
                d[j] -= 2; 
            }
        }
        cout << s << endl;
    }
    return 0;
}
