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
    int att;
    cin >> att;
    while(att--){
        int n;
        string s;
        cin >> n >> s;
        if(s[0] == '2' && s[1] == '0' && s[2] == '2' && s[3] == '0') cout << "YES" << endl;
        else if(s[n-1] == '0' && s[n-2] == '2' && s[n-3] == '0' && s[n-4] == '2') cout << "YES" << endl;
        else{
            bool f1 = 0, f2 = 0, f3 = 0;
            bool fm1 = 0, fm2 = 0, fm3 = 0;
            bool em1 = 0, em2 = 0, em3 = 0;
            bool e1 = 0, e2 = 0, e3 = 0;
            if(s[0] == '2' && s[1] == '0' && s[2] == '2') f1 = 1;
            if(s[0] == '2' && s[1] == '0') f2 = 1;
            if(s[0] == '2') f3 = 1;
            if(s[n-1] == '0') e1 = 1;
            if(s[n-1] == '0' && s[n-2] == '2') e2 = 1;
            if(s[n-1] == '0' && s[n-2] == '2' && s[n-3] == '0') e3 = 1;
            if((f1 && e1) || (f2 && e2) || (f3 && e3)) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}