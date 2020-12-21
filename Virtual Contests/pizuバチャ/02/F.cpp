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
    int n, m;
    cin >> n >> m;
    V<P> ans(m);
    V<V<P>> sort_array(n);
    Srep(m){
        int p, y;
        cin >> p >> y;
        p--;
        sort_array[p].push_back(P(y, i));
    }
    Srep(n) sort(all(sort_array[i]));
    Srep(n){
        int temp = 1;
        Lrep(j,0,sort_array[i].size()){
            ans[sort_array[i][j].S].F = i + 1;
            ans[sort_array[i][j].S].S = temp;
            temp++;
        }
    }
    Srep(m){
        string left = "000000", right = "000000";
        left += to_string(ans[i].F);
        right += to_string(ans[i].S);
        cout << left.substr(left.size() - 6, 6)
            << right.substr(right.size() - 6, 6) << endl;
    }
}