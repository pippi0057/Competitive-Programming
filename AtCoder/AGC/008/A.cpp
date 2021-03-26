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
template <class T> bool chmin(T& a, T b){ if(a > b){ a = b; return 1; } return 0; }
template <class T> bool chmax(T& a, T b){ if(a < b){ a = b; return 1; } return 0; }

void Main(){
    int x, y;
    cin >> x >> y;
    if(x > 0 && y > 0){
        if(x <= y) cout << y - x << endl;
        else cout << min(2 + x - y, 1 + y + x) << endl;
    }else if(x > 0 && y < 0){
        if(x == abs(y)) cout << 1 << endl;
        else cout << abs(abs(x) - abs(y)) + 1 << endl;
    }else if(x < 0 && y > 0){
        if(abs(x) == y) cout << 1 << endl;
        else cout << abs(abs(x) - abs(y)) + 1 << endl;
    }else if(x < 0 && y < 0){
        if(x <= y) cout << y - x << endl;
        else cout << 2 + abs(y) - abs(x) << endl;
    }else if(x == 0){
        if(y == 0) cout << 0 << endl;
        if(y < 0) cout << abs(y) + 1 << endl;
        if(y > 0) cout << y << endl;
    }else if(y == 0){
        if(x == 0) cout << 0 << endl;
        if(x < 0) cout << abs(x) << endl;
        if(x > 0) cout << 1 + abs(x) << endl;
    }
}

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(10) << fixed;
    Main();
}