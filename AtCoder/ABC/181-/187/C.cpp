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
#define vm vector<mint>
#define vvi vector<vi>
#define vdb vector<db>
#define vb vector<bool>
#define V vector

signed main(){
    setup;
    int n;
    cin >> n;
    map<string, int> normal, ex_mark;
    set<string> s;
    Srep(n){
        string input;
        cin >> input;
        if(input[0] == '!'){
            input.erase(0, 1);
            s.insert(input);
            ex_mark[input]++;
        }else{
            s.insert(input);
            normal[input]++;
        }
    }
    for(auto x : s){
        if(normal[x] >= 1 && ex_mark[x] >= 1){
            cout << x << endl;
            return 0;
        }
    }
    cout << "satisfiable" << endl;
}