#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define ll long long int
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
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }

void Main(){
    ll k = 0;
    vector<string> s(3);
    for(auto& x : s) cin >> x;
    vector<ll> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    map<char,ll> m;
    set<char> counter;
    for(auto a : s) for(auto x : a) counter.insert(x);
    for(auto x : counter){ m[x] = k; k++; }
    if(k > 10){ cout << "UNSOLVABLE" << endl; return; }
    do{
        bool ok = 1;
        vector<ll> sum(3);
        rep(3){
            if(!v[m[s[i][0]]]) ok = 0;
            for(auto x : s[i]){ sum[i] *= 10; sum[i] += v[m[x]]; }
        }
        if(ok && sum[0] + sum[1] == sum[2]){
            for(auto x : sum) cout << x << endl;
            return;
        }
    }while(next_permutation(all(v)));
    cout << "UNSOLVABLE" << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}