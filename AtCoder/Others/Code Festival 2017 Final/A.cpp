#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979;
#define speed\
    cin.tie(0);\
    ios::sync_with_stdio(false);
#define int long long int
#define db double
#define ldb long double
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

int32_t main(){
    vi c(26,0);
    string s;
    cin >> s;
    bool ok = 1;
    Srep(s.size()) c[s[i]-'A']++;
    Srep(26){
        if(i == 0) if(c[i] > 4) ok = 0;
        else if(i == 1) if(c[i] != 1) ok = 0;
        else if(i == 7) if(c[i] != 1) ok = 0;
        else if(i == 8) if(c[i] != 1) ok = 0;
        else if(i == 10) if(c[i] != 1) ok = 0;
        else if(i == 17) if(c[i] != 1) ok = 0;
        else if(c[i] != 0) ok = 0;
    }
    cout << (ok ? "YES" : "NO") << endl;
}