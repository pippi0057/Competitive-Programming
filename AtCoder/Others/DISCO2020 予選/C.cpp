#include <bits/stdc++.h>
using namespace std;
#define int long long int
const double pi = 3.14159265358979;
const int inf = 1e13;
vector<int> dx = {0, 1, 0, -1, 1, 1, -1, -1};
vector<int> dy = {1, 0, -1, 0, 1, -1, 1, -1};
#define pii pair<int,int>
#define endl "\n"
#define dtor(deg) (((deg)/360)*2*pi)
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
struct Edge { int to, cost; Edge(int to, int cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }

void Main(){
    int h, w, k, cnt = 1;
    cin >> h >> w >> k;
    vv(bool, cake, h, w);
    vv(int, ans, h, w);
    vector<int> hs;
    rep(h) rep(j,w){
        char input;
        cin >> input;
        cake[i][j] = input == '#';
    }
    {
        bool fi = 1;
        hs.push_back(0);
        rep(h){
            rep(j,w) if(cake[i][j]){ if(fi){ fi = 0; }else{ hs.push_back(i); }}
        }
    }
    rep(hs.size()-1){
        vector<int> ws;
        bool fi = 1;
        ws.push_back(0);
        rep(j,w){
            rep(k,hs[i],hs[i+1]) if(cake[k][j]){ if(fi){ fi = 0; }else{ ws.push_back(j); }}
        }
        rep(j,ws.size()-1){
            rep(k,hs[i],hs[i+1]) rep(l,ws[j],ws[j+1]) ans[k][l] = cnt;
            cnt++;
        }
        rep(j,ws.size()) cout << ws[j] << " ";
        cout << endl;
    }
    rep(h){
        rep(j,w) cout << ans[i][j] << " ";
        cout << endl;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}
