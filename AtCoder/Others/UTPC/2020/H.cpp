#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define all(v) v.begin(), v.end()
#define rep(i, begin, end) for(int i = begin; i < (int)(end); i++)
#define contains(v, x) (find(all(v), x) != v.end())
template<class T> bool chmin(T& a, T b){ if (a > b){ a = b; return true; } return false; }
template<class T> bool chmax(T& a, T b){ if (a < b){ a = b; return true; } return false; }
template<class T> T roundup(T a, T b){ return (a + b - 1) / b; }
const double PI = 3.14159265359;
const vector<int> dy = {0, 1, 0, -1, 1, 1, -1, -1, 0};
const vector<int> dx = {1, 0, -1, 0, 1, -1, 1, -1, 0};
/*
#include <boost/multiprecision/cpp_int.hpp>
using Bint = mp::cpp_int; */
using ll = long long;
struct Edge{ int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
constexpr ll MOD = (ll)1e9 + 7;
constexpr ll INF = (ll)1e9;
using P = pair<ll, ll>;
using Graph = vector<vector<int>>;
/* #include <atcoder/all>
using namespace atcoder;
using mint = modint; */

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // mint::set_mod(MOD);
    
    int h, w;
    cin >> h >> w;
    vector s(h, vector(w, '.'));
    rep(i, 0, h) rep(j, 0, w) cin >> s[i][j];
    
    int ans = 0;
    rep(i, 0, s.size()){
        int cnt = count(all(s[i]), '.');
        if(cnt == 0 || cnt == w) s.erase(s.begin() + i), i--, ans++;
    }
    h = s.size();
    
    if(h == 0) goto end;
    rep(j, 0, s[0].size()){
        int cnt = 0;
        rep(i, 0, h) cnt += (s[i][j] == '#');
        if(cnt == 0 || cnt == h){
            rep(i, 0, h) s[i].erase(s[i].begin() + j);
            ans++;
            j--;
        }
    }
    w = s[0].size();
    
    if(w == 0) goto end;
    rep(i, 0, s.size()){
        int cnt = count(all(s[i]), '.');
        if(cnt == 0 || cnt == w) s.erase(s.begin() + i), i--, ans++;
    }
    h = s.size();
    
    if(h == 0) goto end;
    rep(j, 0, s[0].size()){
        int cnt = 0;
        rep(i, 0, h) cnt += (s[i][j] == '#');
        if(cnt == 0 || cnt == h){
            rep(i, 0, h) s[i].erase(s[i].begin() + j);
            ans++;
            j--;
        }
    }
    w = s[0].size();
    end:;
    cout << ans << endl;
}
