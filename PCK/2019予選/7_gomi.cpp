#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<stack>

#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.bigin(), a.end())
#define Srep(n) for(int i = 0; i < (n); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>

using namespace std;

int64_t gcd(int64_t x, int64_t y){
    return x % y == 0 ? y : gcd(y, x % y);
}

int64_t lcm(int64_t a, int64_t b){
    return a * b / gcd(a, b);
}

int main(){
    int n, ans = 0;
    cin >> n;
    vi p(n);
    Srep(n) cin >> p[i];
    int64_t LCM = p[0];
    Srep(n) LCM = lcm(LCM,p[i]);
    vi64 q(LCM);
    Srep(LCM) q[i] = 0;
    Srep(LCM) Lrep(j,0,n) if(i % p[j] == 0){
        int64_t sum = 1;
        Lrep(k,0,j) sum *= 2;
        q[i] += sum;
    }
    Vsort(q);
    int a,b;
    Srep(LCM) if(q[i] != q[i + 1]){
        a = q[i + 1];
        b = i + 1;
        break;
    }
    Srep(b) q[i] = a;
    Srep(LCM) if(q[i] != q[i + 1]) ans++;
    cout << ans << endl;
}