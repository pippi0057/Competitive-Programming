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
    int n, ans = 0;
    cin >> n;
    vi h(n);
    Srep(n) cin >> h[i];
    h.push_back(0);
    queue<vi> task;
    vi ftemp;
    Srep(h.size()){
        if(h[i] == 0 && ftemp.size()){
            task.push(ftemp);
            ftemp.clear();
        }else if(h[i] != 0) ftemp.push_back(h[i]);
    }
    while(!task.empty()){
        vi f = task.front();
        task.pop();
        int low = *min_element(all(f));
        Srep(f.size()) f[i] -= low;
        f.push_back(0);
        vi temp;
        Srep(f.size()){
            if(f[i] == 0 && temp.size()){
                task.push(temp);
                temp.clear();
            }else if(f[i] != 0) temp.push_back(f[i]);
        }
        ans += low;
    }
    cout << ans << endl;
}