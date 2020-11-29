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
    int n,x;
    while(true){
        cin >> n >> x;
        int temp = 0;
        if((n == 0)&&(x == 0)) return 0;
        Lrep(i,1,n-1) Lrep(j,i+1,n) Lrep(k,j+1,n+1){
            if(i + j + k == x) temp++;
        }
        cout << temp << endl;
    }
}
