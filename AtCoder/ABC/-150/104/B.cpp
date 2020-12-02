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
    string s;
    cin >> s;
    auto solve = [s]() -> bool{
        if(s[0] != 'A') return 0;
        if(65 <= s[1] && s[1] <= 90) return 0;
        int temp = 0, ng = 0;
        Lrep(i,2,s.size()-1){
            if(97 <= s[i] && s[i] <= 122) continue;
            else if(s[i] == 'C'){
                if(ng) return 0;
                else{
                    temp++;
                    ng = 1;
                }
            }else return 0;
        }
        if(65 <= s[s.size()-1] && s[s.size()-1] <= 90) return 0;
        if(temp == 1) return 1;
        else return 0;
    };
    cout << (solve() ? "AC" : "WA") << endl;
}
