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

signed main(){
    setup;
    int n, ans = 0;
    cin >> n;
    vi as(n), bs(n);
    Srep(n){
        int input;
        cin >> input;
        if(i == 0) as[i] = input;
        else as[i] = as[i-1] + input;
    }
    Srep(n){
        int input;
        cin >> input;
        if(i == 0) bs[i] = input;
        else bs[i] = bs[i-1] + input;
    }
    Srep(n){
        int temp = 0;
        if(i == 0) temp += as[0] + bs[n-1];
        else temp += as[i] + bs[n-1] - bs[i-1];
        ans = max(ans, temp);
    }
    cout << ans << endl;
}
