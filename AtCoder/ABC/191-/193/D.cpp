#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const double pi = 3.14159265358979;
const ll inf = 1e17;
const int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const int dy[] = {1, 0, -1, 0, 1, -1, 1, -1};
#define pii pair<int,int>
#define pll pair<ll,ll>
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
struct Edge { int to; ll cost; Edge(int to, ll cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }

void Main(){
    int k;
    double a = 0, b;
    string s, t;
    cin >> k >> s >> t;
    vector<int> card(9, k);
    vector<int> A(9);
    vector<int> B(9);
    s = s.substr(0, 4);
    t = t.substr(0, 4);
    for(auto x : s){ card[x - '1']--; A[x - '1']++; }
    for(auto x : t){ card[x - '1']--; B[x - '1']++; }
    int temp = 0;
    rep(9) temp += card[i];
    b = (temp) * (temp - 1) / 2;
    auto ok = [card](int a, int b) -> bool{
        if(a == b) return card[a] >= 2;
        else return card[a] >= 1 && card[b] >= 1;
    };
    rep(9){
        rep(j,9){
            if(!ok(i, j)) continue;
            A[i]++;
            B[j]++;
            int aoki = 0;
            int takahashi = 0;
            rep(k,9) takahashi += (k + 1) * pow(10, A[k]);
            rep(k,9) aoki += (k + 1) * pow(10, B[k]);
            if(takahashi > aoki){
                if(i == j) a += card[i] * (card[i] - 1) / 2;
                else a += card[i] * card[j] / 2;
            }
            A[i]--;
            B[j]--;
        }
    }
    cout << a / b << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}