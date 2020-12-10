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
    vi input(3);
    int sum = 0, temp, ans = 0;
    Srep(3){
        cin >> input[i];
        sum += input[i];
    }
    sort(all(input));
    if(sum % 2 == (input[2] * 3) % 2){
        temp = input[2];
        if(temp % 2 != input[0] % 2){
            ans++;
            Srep(2) input[i]++;
        }
    }else{
        temp = input[2] + 1;
        ans++;
        if(input[1] % 2 == temp % 2) input[0]++;
        else input[1]++;
    }
    Srep(2) ans += (temp - input[i]) / 2;
    cout << ans << endl;
}