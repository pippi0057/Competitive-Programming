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
    int n, temp = 0;
    bool ok = 1;
    string s;
    cin >> n >> s;
    if(n == 1){
        if(s == "1") cout << 20000000000 << endl;
        else cout << 10000000000 << endl;
    }else if(n == 2){
        if(s == "10") cout << 10000000000 << endl;
        else if(s == "11") cout << 999999999 << endl;
        else cout << 10000000000 << endl;
    }else{
        for(int i = 0; i < n - 2; i++){
            if(s[i] == '1' && s[i+1] == '0' && s[i+2] == '1') temp++;
        }
        if(s[0] != '1' || s[1] != '0' || s[2] != '1') temp++;
        if(s[n-3] != '1' || s[n-2] != '0' || s[n-1] != '1') temp++;
        cout << 10000000001 - temp << endl;
    }
}