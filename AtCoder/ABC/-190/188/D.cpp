#include <bits/stdc++.h>
using namespace std;
#define int long long int
const double pi = 3.14159265358979;
const int inf = 1e13;
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
#define rrep(...) overload(__VA_ARGS__,_null,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define vv(type,name,size,...) vector<vector<type>> name(size,vector<int>(__VA_ARGS__))
#define ForEach(a,b) for_each(a.begin(),a.end(),b)
struct Edge { int to, cost; Edge(int to, int cost) : to(to), cost(cost) {} };
using Graph = vector<vector<Edge>>;

void Main(){
    int n, c, ans = 0;
    cin >> n >> c;
    vector<pair<int,int>,int> plan(n);
    set<int> Split;
    rep(n){
        int a, b, m;
        cin >> a >> b >> m;
        Split.insert(a-1);
        Split.insert(b);
        plan[i].first.first = a - 1;
        plan[i].first.second = b;
        plan[i].second = m;
    }
    vector<int> cnt(Split.size()-1);
    vector<int> Split_v(Split.size());
    int temp = 0;
    map<int,int> access_1, access_2;
    for(auto i : Split){
        if(temp != Split.size() - 1) access_1[i] = temp;
        if(temp != 0) access_2[i] = temp - 1;
        Split_v[temp] = i;
        temp++;
    }
    rep(Split_v.size()-1) cnt[i] = Split_v[i+1] - Split_v[i];
    vector<int> imos(Split.size()-1);
    rep(n){
        imos[access_1[plan[i].first.first]] += plan[i].second;
        imos[access_2[plan[i].first.second]] -= plan[i].second;
    }
    int now = 0;
    rep(imos.size()){
        now += imos[i];
        ans += min(c, now) * cnt[i];
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    //int n; cin >> n; rep(n)
    Main();
}