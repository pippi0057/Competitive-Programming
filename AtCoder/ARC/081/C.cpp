#include <bits/stdc++.h>
using namespace std;
#define int long long int
const double pi = 3.14159265358979;
const int inf = 1e13;
#define setup cin.tie(0); ios::sync_with_stdio(false); cout << setprecision(20) << fixed;
#define db double
#define P pair<int,int>
#define F first
#define S second
#define endl "\n"
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
#define vdb vector<db>
#define vb vector<bool>

signed main(){
    setup;
    int n;
    vi edge;
    vb ok(1e9+100, 0);
    cin >> n;
    Srep(n){
        int input;
        cin >> input;
        if(ok[input]){
            edge.push_back(input);
            ok[input] = 0;
        }else ok[input] = 1;
    }
    sort(all(edge));
    if(edge.size()) cout << edge[edge.size()-1] * edge[edge.size()-2] << endl;
    else cout << 0 << endl;
}