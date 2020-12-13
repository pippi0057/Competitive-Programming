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
#define RoundUp(a,b) ((a) % (b) ? (a) / (b) + 1 : (a) / (b))
#define vi vector<int>
#define vvi vector<vi>
#define vdb vector<db>
#define vb vector<bool>
#define V vector

signed main(){
    setup;
    int n, m;
    cin >> n >> m;
    if(n == m){
        cout << 0 << endl;
        return 0;
    }
    if(m == 0){
        cout << 1 << endl;
        return 0;
    }
    vi in(m);
    Srep(m) cin >> in[i];
    sort(all(in));
    vi stamp;
    stamp.push_back(0);
    Srep(m) stamp.push_back(in[i]);
    stamp.push_back(n+1);
    vi dis;
    int g;
    bool fi = 1;
    Srep(stamp.size()-1){
        int temp;
        if(stamp[i+1] - stamp[i] == 1) continue;
        temp = stamp[i+1] - stamp[i] - 1;
        if(fi){
            g = temp;
            fi = 0;
        }else g = min(g, temp);
        dis.push_back(temp);
    }
    int ans = 0;
    Srep(dis.size()){
        ans += RoundUp(dis[i], g);
    }
    cout << ans << endl;
}