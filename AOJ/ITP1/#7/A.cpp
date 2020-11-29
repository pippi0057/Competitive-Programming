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
    int m,f,r;
    while(true){
        cin >> m >> f >> r;
        if((m == -1)&&(f == -1)&&(r == -1)) return 0;
        if((m == -1)||(f == -1)) cout << 'F' << endl;
        else if(m + f >= 80) cout << 'A' << endl;
        else if(m + f >= 65) cout << 'B' << endl;
        else if(m + f >= 50) cout << 'C' << endl;
        else if(m + f >= 30){
            if(r >= 50) cout << 'C' << endl;
            else cout << 'D' << endl;
        }
        else cout << 'F' << endl;
    }
}
