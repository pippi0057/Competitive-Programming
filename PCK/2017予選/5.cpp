#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define rep(i, begin, end) for(auto i = (begin); i < (end); i++)
#define rrep(i, end, begin) for(auto i = (end) - 1; i >= (begin); i--)
template<class T> inline bool chmin(T& a, T b){ if (a > b){ a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b){ if (a < b){ a = b; return true; } return false; }
template<class T> inline T roundup(T a, T b){ return (a + b - 1) / b; }
constexpr int dy[] = {0, 1, 0, -1, 1, 1, -1, -1, 0};
constexpr int dx[] = {1, 0, -1, 0, 1, -1, 1, -1, 0};
using ll = long long;
using ull = unsigned long long;
constexpr ll INF = 1e9;
constexpr ll MOD = 1e9 + 7;
struct Edge{ int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int x, y;
    cin >> x >> y;
    
    int g = __gcd(x, y);
    int p = x / g, q = y / g;
    cout << (p - 1 + q - 1) * g + 2 + g - 1 << endl;
}