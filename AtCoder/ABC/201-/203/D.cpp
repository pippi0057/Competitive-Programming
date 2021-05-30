#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
const ll inf = 1e17;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define pii pair<int,int>
#define pll pair<ll,ll>
#define endl "\n"
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
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define vv(type,name,size,...) vector<vector<type>> name(size,vector<type>(__VA_ARGS__))
#define ForEach(a,b) for_each(a.begin(),a.end(),b)
#define NextAfter(x) x = nextafter(x, INFINITY)
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;

int ans = 1000000100, n, k, mid;
vector<int> nums(40000);
vector<vector<int>> bucket(40000, vector<int>(40000)), a(810, vector<int>(810));

void Add(int m){
    bucket[m/40000][m%40000]++;
    nums[m/40000]++;
    return;
}

void Remove(int m){
    bucket[m/40000][m%40000]--;
    nums[m/40000]--;
    return;
}

int Get(){
    int p = 0, x = mid;  
    for(; p < 40000; p++) {  
        if (nums[p] < x)  
            x -= nums[p];  
        else  
            break;  
    }
    rep(40000) {  
        x -= bucket[p][i];  
        if (x <= 0)  
            return p * 40000 + i;  
    }  
    return -1;  
}

void Main(){
    bool cmd = 1;
    cin >> n >> k;
    mid = (k * k) / 2 + 1;
    rep(n) rep(j,n) cin >> a[i][j];
    rep(k) rep(j,k) Add(a[i][j]);
    chmin(ans, Get());
    for(int i = 0; i < n - k + 1; i++){
        if(cmd){
            for(int j = 0; j < n - k; j++){
                for(int l = 0; l < k; l++){
                    Add(a[i+l][j+k]);
                    Remove(a[i+l][j]);
                }
                chmin(ans, Get());
            }
        }else{
            for(int j = n - k; j >= 0; j--){
                for(int l = 0; l < k; l++){
                    Add(a[i+l][j]);
                    Remove(a[i+l][j+k]);
                }
                chmin(ans, Get());
            }
        }
        chmin(ans, Get());
        if(i == n - k) break;
        if(cmd){
            for(int j = n - k; j < n; j++){
                Add(a[i+k][j]);
                Remove(a[i][j]);
            }
        }else{
            for(int j = 0; j < k; j++){
                Add(a[i+k][j]);
                Remove(a[i][j]);
            }
        }
        cmd = cmd ? 0 : 1;
        chmin(ans, Get());
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}