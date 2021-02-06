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

vi memo(500,inf);
int fuc(int n){
    if(n == 0 || n == 1) return 1;
    else{
        if(memo[n] == inf) return memo[n] = n * fuc(n-1);
        else return memo[n];
    }
}

signed main(){
    setup;
    int l;
    cin >> l;
    l--;
    int ans = l;
    vi stock(12, 0);
    stock[2] = 8;
    stock[3] = 4;
    stock[5] = 2;
    stock[7] = 1;
    stock[11] = 1;
    for(int i = 1; i <= 10; i++){
        ans *= (l - i);
        if(ans % 2 == 0 && stock[2]){
            ans /= 2;
            stock[2]--;
        }
        if(ans % 3 == 0 && stock[3]){
            ans /= 3;
            stock[3]--;
        }
        if(ans % 5 == 0 && stock[5]){
            ans /= 5;
            stock[5]--;
        }
        if(ans % 7 == 0 && stock[7]){
            ans /= 7;
            stock[7]--;
        }
        if(ans % 11 == 0 && stock[11]){
            ans /= 11;
            stock[11]--;
        }
    }
    cout << ans << endl;
}