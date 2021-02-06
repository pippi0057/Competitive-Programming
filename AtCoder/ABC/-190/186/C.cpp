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

string to_eight(int n){
    string res;
    while(n > 0){
        res += (n % 8) - '0';
        n /= 8;
    }
    reverse(all(res));
    return res;
}

signed main(){
    setup;
    int n, ans = 0;
    cin >> n;
    Lrep(i, 1, n+1){
        bool ok = 1;
        int temp1 = i, temp2 = i;
        while(temp2 > 0){
            if(temp1 % 10 == 7) ok = 0;
            if(temp2 % 8 == 7) ok = 0;
            temp1 /= 10;
            temp2 /= 8;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
}