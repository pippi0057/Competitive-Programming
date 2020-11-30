#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979;
#define setup\
    cin.tie(0);\
    ios::sync_with_stdio(false);\
    cout << setprecision(20) << fixed;
#define int long long int
#define db double
#define P pair<int,int>
#define F first
#define S second
#define dtor(deg) (((deg)/360)*2*pi)
#define rtod(rad) (((rad)/2/pi)*360)
#define all(a) a.begin(),a.end()
#define Srep(n) for(int i = 0; i < n; i++)
#define Lrep(i,a,n) for(int i = a; i < n; i++)
#define Brep1st(n) for(int bit = 0; bit < (1 << n); bit++)
#define Brep2nd(n) Srep(n) if(bit >> i & 1)
#define rep2d(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vvi vector<vi>
#define vc vector<char>
#define vvc vector<vc>

struct UnionFind{
    vi parent,siz;
    UnionFind(int n) : parent(n), siz(n,1){
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    int root(int x){
        while(parent[x] != x){
            x = parent[x] = parent[parent[x]];
        }
        return x;
    }
    bool unite(int x, int y){
        x = root(x);
        y = root(y);
        if(x == y) return false;
        if(siz[x] < siz[y]) swap(x,y);
        siz[x] += siz[y];
        parent[y] = x;
        return true;
    }
    bool same(int x, int y) {return root(x) == root(y); }
    int size(int x) {return siz[root(x)]; }
};

signed main(){
    setup;
    int n,m;
    cin >> n >> m;
    UnionFind city(n);
    Srep(m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        city.unite(a,b);
    }
    set<int> ans;
    Srep(n) ans.insert(city.root(i));
    cout << ans.size() - 1 << endl;
}
