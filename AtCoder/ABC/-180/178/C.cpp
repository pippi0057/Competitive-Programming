#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>

#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.begin(), a.end())
#define Srep(n) for(int i = 0; i < (n); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>

using namespace std;

const int64_t mod = 1000000007;

int64_t modinv(int64_t a, int64_t m) {
    int64_t b = m, u = 1, v = 0;
    while (b) {
        int64_t t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
    int n, a = 1;
    cin >> n;
    Lrep(i,1,n+1){
        a *= i;
        a %= mod;
    }
    int b = 1;
    Lrep(i,1,n-1){
        b *= i;
        b %= mod;
    }
    cout << a << endl << b << endl;
    b *= 2;
    b %= mod;
    int c = a * modinv(b,mod) % mod;  
    
    c *= 2;
    c %= mod;
    cout << c << endl;
}