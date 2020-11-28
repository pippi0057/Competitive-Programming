// gotoキャンペーン
// 模範的なスパゲッティコード
#include <bits/stdc++.h>
using namespace std;
const double pi = 3.14159265358979;
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

int n, ans = 0, sum = 0, i = 0, temp, c;
vi a;

int32_t main(){
    goto start;
    out:;
    cout << ans << endl;
    return 0;
    solve:;
    sum -= a[i];
    temp = sum % 1000000007;
    ans += temp * a[i];
    ans %= 1000000007;
    i++;
    if(i < n - 1) goto solve;
    else goto out;
    in:;
    input:;
    cin >> c;
    a.push_back(c);
    i++;
    if(i < n) goto input;
    i = 0;
    goto sm;
    start:;
    cin >> n;
    i = 0;
    goto in;
    sm:;
    takesum:;
    sum += a[i];
    i++;
    if(i < n) goto takesum;
    i = 0;
    goto solve;
}   