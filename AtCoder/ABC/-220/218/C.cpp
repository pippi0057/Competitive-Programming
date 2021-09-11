#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll int64_t
#define u32 uint32_t
#define u64 uint64_t
constexpr ll inf = 1e17;
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
#define Auto const auto
#define all(a) a.begin(),a.end()
#define overload(_1,_2,_3,_4,name,...) name
#define _rep1(n) for(int i = 0; i < (n); i++)
#define _rep2(i,n) for(int i = 0; i < (n); i++)
#define _rep3(i,a,b) for(int i = (a); i < (b); i++)
#define _rep4(i,a,b,c) for(int i = (a); i < (b); i += (c))
#define rep(...) overload(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rrep1(n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep2(i,n) for(int i = (n) - 1; i >= 0; i--)
#define _rrep3(i,a,b) for(int i = (b) - 1; i >= (a); i--)
#define _rrep4(i,a,b,c) for(int i = (b) - 1; i >= (a); i -= (c))
#define rrep(...) overload(__VA_ARGS__,_rrep4,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
#define vv(type,name,size,...) vector<vector<type>> name(size,vector<type>(__VA_ARGS__))
template <class T> inline bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> inline bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;

void Main(){
    int n, x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> n;
    vector s(n, vector(n, 'a')), t(n, vector(n, 'a'));
    for(auto& v : s) for(auto& x : v) cin >> x;
    for(auto& v : t) for(auto& x : v) cin >> x;
    for(x1 = 0; x1 < n; x1++){
        bool ok = 1;
        for(int i = 0; i < n; i++) if(s[x1][i] == '#') ok = 0;
        if(!ok) break;
    }
    for(x2 = 0; x2 < n; x2++){
        bool ok = 1;
        for(int i = 0; i < n; i++) if(t[x2][i] == '#') ok = 0;
        if(!ok) break;
    }
    for(x3 = 0; x3 >= 0; x3--){
        bool ok = 1;
        for(int i = 0; i < n; i++) if(s[x3][i] == '#') ok = 0;
        if(!ok) break;
    }
    for(x4 = 0; x4 >= 0; x4--){
        bool ok = 1;
        for(int i = 0; i < n; i++) if(t[x4][i] == '#') ok = 0;
        if(!ok) break;
    }
    for(y1 = 0; y1 < n; y1++){
        bool ok = 1;
        for(int i = 0; i < n; i++) if(s[i][y1] == '#') ok = 0;
        if(!ok) break;
    }
    for(y2 = 0; y2 < n; y2++){
        bool ok = 1;
        for(int i = 0; i < n; i++) if(t[i][y2] == '#') ok = 0;
        if(!ok) break;
    }
    for(y3 = 0; y3 >= 0; y3--){
        bool ok = 1;
        for(int i = 0; i < n; i++) if(s[i][y3] == '#') ok = 0;
        if(!ok) break;
    }
    for(y4 = 0; y4 >= 0; y4--){
        bool ok = 1;
        for(int i = 0; i < n; i++) if(t[i][y4] == '#') ok = 0;
        if(!ok) break;
    }
    vector S(x3 - x1 + 1, vector(y3 - y1 + 1, 'a')), T(x4 - x2 + 1, vector(y4 - y2 + 1, 'a'));
    for(int i = x1; i <= x3; i++) for(int j = y1; j <= y3; j++){
        S[i-x1][j-y1] = s[i][j];
    }
    for(int i = x2; i <= x4; i++) for(int j = y2; j <= y4; j++){
        T[i-x2][j-y2] = s[i][j];
    }
    bool ans = 1;
    if(S.size() != T.size() || S[0].size() != T[0].size()) ans = 0;
    if(!ans){ cout << "No" << endl; return; }
    for(int i = 0; i < S.size(); i++){
        for(int j = 0; j < S[0].size(); j++){
            if(S[i][j] != T[i][j]) ans = 0;
        }
    }
    if(ans){ cout << "Yes" << endl; return; }
    ans = 1;
    vector _1(x3 - x1, vector(y3 - y1, 'a')), _2(x3 - x1, vector(y3 - y1, 'a')), _3(x3 - x1, vector(y3 - y1, 'a'));
    for(int i = 0, k = S.size() - 1; i < S.size(); i++, k--){
        for(int j = 0, l = S[0].size() - 1; j < S[0].size(); j++, l--){
            _1[l][i] = S[i][j];
            _2[j][k] = S[i][j];
            _3[i][j] = S[k][l];
        }
    }
    for(int i = 0; i < S.size(); i++){
        for(int j = 0; j < S[0].size(); j++){
            if(_1[i][j] != T[i][j]) ans = 0;
        }
    }
    
    if(ans){ cout << "Yes" << endl; return; }
    ans = 1;
    for(int i = 0; i < S.size(); i++){
        for(int j = 0; j < S[0].size(); j++){
            if(_2[i][j] != T[i][j]) ans = 0;
        }
    }
    if(ans){ cout << "Yes" << endl; return; }
    ans = 1;
    for(int i = 0; i < S.size(); i++){
        for(int j = 0; j < S[0].size(); j++){
            if(_3[i][j] != T[i][j]) ans = 0;
        }
    }
    if(ans){ cout << "Yes" << endl; return; }
    cout << "No" << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}