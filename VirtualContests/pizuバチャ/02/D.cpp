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
#define Rrep(i,n,a) for(int i = n - 1; i >= a; i--)
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
    int n, b = 0, c = 0;
    cin >> n;
    vi a(n);
    Srep(n) cin >> a[i];
    bool cmd = 0; // 0:単調非減少 1:単調非増加
    bool cmd2 = 1; // 1:区切った直後
    Srep(n-1){
        if(cmd2){
            if(a[i] == a[i+1]) continue;
            else if(a[i] < a[i+1]){
                cmd = 1;
                cmd2 = 0;
            }else{
                cmd = 0;
                cmd2 = 0;
            }
        }else{
            if(cmd){
                if(a[i] == a[i+1]) continue;
                else if(a[i] < a[i+1]) continue;
                else{
                    cmd2 = 1;
                    b++;
                }
            }else{
                if(a[i] == a[i+1]) continue;
                else if(a[i] > a[i+1]) continue;
                else{
                    cmd2 = 1;
                    b++;
                }
            }
        }
    }
    cmd2 = 1;
    Rrep(i,n,1){
        if(cmd2){
            if(a[i] == a[i-1]) continue;
            else if(a[i] < a[i-1]){
                cmd = 1;
                cmd2 = 0;
            }else{
                cmd = 0;
                cmd2 = 0;
            }
        }else{
            if(cmd){
                if(a[i] == a[i-1]) continue;
                else if(a[i] < a[i-1]) continue;
                else{
                    cmd2 = 1;
                    c++;
                }
            }else{
                if(a[i] == a[i-1]) continue;
                else if(a[i] > a[i-1]) continue;
                else{
                    cmd2 = 1;
                    c++;
                }
            }
        }
    }
    b++; c++;
    cout << min(b, c) << endl;
}