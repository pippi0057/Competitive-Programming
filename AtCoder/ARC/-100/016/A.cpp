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
    vector<bool> push(9);
    rep2d(n,9){
        char input;
        cin >> input;
        if(input == 'x'){
            ans++;
            push[j] = 0;
        }else if(input == 'o' && !push[j]){
            ans++;
            push[j] = 1;
        }else if(input == '.') push[j] = 0;
    }
    cout << ans << endl;
}