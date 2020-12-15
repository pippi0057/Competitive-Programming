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

bool prime(int n){
    if (n < 2) return 0;
    else if (n == 2) return 1;
    else if (n % 2 == 0) return 0;
    long double sqrtn = sqrt(n);
    for (int i = 3; i <= sqrtn; i += 2){
        if (n % i == 0){
            return 0;
        }
    }
    return 1;
}

int solve(int n){
    if(n == 1) return 0;
    int ret = 0;
    while(prime(n)){
        n--;
        ret++;
    }
    if(n == 1) return ret;
    for(int i = 2; i <= (db)sqrt(n); i++){
        if(n % i == 0){
            ret += solve(i) + 1;
            break;
        }
    }
    return ret;
}

int32_t main(){
    speed;
    int n;
    cin >> n;
    vi a(n);
    Srep(n) cin >> a[i];
    Srep(n) cout << solve(a[i]) << endl;
}   