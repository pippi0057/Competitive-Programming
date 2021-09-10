#include <bits/stdc++.h>
using namespace std;
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
    int h, n;
    cin >> h >> n;
    vector<vector<bool>> room(h, vector<bool>(5, 1));
    vector<vector<int>> dp(h, vector<int>(4));
    while(n--){
        int x, y;
        cin >> x >> y;
        room[h-y-1][x] = 0;
    }
    // 0: left
    // 1: center
    // 2: right
    // 3: left / right
    // 4: no box
    rep(i,1,h){
        if(room[i][0] && room[i][1] && room[i-1][0] && room[i-1][1]){
            if(i == 1) dp[i][0] = 1;
            else chmax(dp[i][0], max({dp[i-2][0], dp[i-2][1], dp[i-2][2], dp[i-2][3], dp[i-2][4], dp[i-1][2]}) + 1);
        }
        if(room[i][1] && room[i][2] && room[i-1][1] && room[i-1][2]){
            if(i == 1) dp[i][1] = 1;
            else chmax(dp[i][1], max({dp[i-2][0], dp[i-2][1], dp[i-2][2], dp[i-2][3], dp[i-2][4]}) + 1);
        }
        if(room[i][2] && room[i][3] && room[i-1][2] && room[i-1][3]){
            if(i == 1) dp[i][2] = 1;
            else chmax(dp[i][2], max({dp[i-2][0], dp[i-2][1], dp[i-2][2], dp[i-2][3], dp[i-2][4], dp[i-1][0]}) + 1);
        }
        if(room[i][0] && room[i][1] && room[i][2] && room[i][3] &&
            room[i-1][0] && room[i-1][1] && room[i-1][2] && room[i-1][3]){
            if(i == 1) dp[i][3] = 2;
            else chmax(dp[i][3], max({dp[i-2][0], dp[i-2][1], dp[i-2][2], dp[i-2][3], dp[i-2][4]}) + 2);
        }
        if(i == 1) dp[i][4] = 0;
        else dp[i][4] = max({dp[i-1][0], dp[i-1][1], dp[i-1][2], dp[i-1][3], dp[i-1][4]});
    }
    cout << max({dp[h-1][0], dp[h-1][1], dp[h-1][2], dp[h-1][3], dp[h-1][4]}) << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << setprecision(10) << fixed;
    Main();
}