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
    int n, m, g, ans = 0;
    cin >> n >> m;
    if(n == m){
        cout << 0 << endl;
        return 0;
    }
    if(m == 0){
        cout << 1 << endl;
        return 0;
    }
    vi a(m);
    vi dis;
    Srep(m){
        cin >> a[i];
        a[i]--;
    }
    sort(all(a));
    if(a[0] == 0 && a[m-1] == n - 1){
        Lrep(i,1,m-1){
            int temp;
            if(i == 0) g = temp = a[i] - 1;
            else temp = a[i] - a[i-1] - 1;
            g = min(temp, g);
            dis.push_back(temp);
        }
        int temp = n - a[m-2] - 2;
        g = min(temp, g);
        dis.push_back(temp);
        Srep(dis.size()) ans += RoundUp(dis[i], g);
    }else if(a[0] == 0){
        Lrep(i,1,m){
            int temp;
            if(i == 0) g = temp = a[i] - 1;
            else temp = a[i] - a[i-1] - 1;
            g = min(temp, g);
            dis.push_back(temp);
        }
        int temp = n - a[m-1] - 1;
        g = min(temp, g);
        dis.push_back(temp);
        Srep(dis.size()) ans += RoundUp(dis[i], g);
    }else if(a[m-1] == n - 1){
        Srep(m-1){
            int temp;
            if(i == 0) g = temp = a[i];
            else temp = a[i] - a[i-1] - 1;
            g = min(temp, g);
            dis.push_back(temp);
        }
        int temp = n - a[m-2] - 2;
        g = min(temp, g);
        dis.push_back(temp);
        Srep(dis.size()) ans += RoundUp(dis[i], g);
    }else{
        Srep(m){
            int temp;
            if(i == 0) g = temp = a[i];
            else temp = a[i] - a[i-1] - 1;
            g = min(temp, g);
            dis.push_back(temp);
        }
        Srep(dis.size()) ans += RoundUp(dis[i], g);
    }
    cout << ans << endl;
}