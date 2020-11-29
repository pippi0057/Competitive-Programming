#include <bits/stdc++.h>
#define all(a) a.begin(),a.end()
#define Srep(n) for(int64_t i = 0; i < int64_t(n); i++)
#define Lrep(i,a,n) for(int64_t i = int64_t(a); i < int64_t(n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define rep2d(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vi>
#define vvi64 vector<vi64>
#define vc vector<char>
#define vvc vector<vc>
using namespace std;

int main(){
    int r,c;
    cin >> r >> c;
    vvi a(r+1,vi(c+1));
    Srep(r){
        int temp = 0;
        Lrep(j,0,c){
            cin >> a[i][j];
            temp += a[i][j];
        }
        a[i][c] = temp;
    }
    Srep(c){
        int temp = 0;
        Lrep(j,0,r){
            temp += a[j][i];
        }
        a[r][i] = temp;
    }
    Srep(r){
        a[r][c] += a[i][c];
    }
    Srep(r+1){
        Lrep(j,0,c+1){
            cout << a[i][j];
            if(j != c) cout << ' ';
        }
        cout << endl;
    }
}
