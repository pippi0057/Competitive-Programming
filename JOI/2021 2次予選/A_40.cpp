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
#define RoundUp(a,b) (a % b ? a / b + 1 : a / b)
#define vi vector<int>
#define vvi vector<vi>
#define vdb vector<db>
#define vb vector<bool>
#define V vector

signed main(){
    setup;
    int n, a, cnt = 0, ans = 0, now;
    string s = "x";
    cin >> n >> a;
    Srep(n){
        char input;
        cin >> input;
        s += input;
    }
    s += 'x';
    for(auto i : s) if(i == '#') cnt++;
    bool cmd = 1;
    now = a;
    while(cnt > 0){
        ans++;
        if(cmd) now++;
        else now--;
        if(s[now] == 'x') cmd = (cmd ? 0 : 1);
        if(s[now] == '#'){
            cmd = (cmd ? 0 : 1);
            s[now] = '.';
            cnt--;
        }
    }
    cout << ans << endl;
}