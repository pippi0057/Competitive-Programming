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

int gcd(int x, int y){
    return x % y == 0 ? y : gcd(y, x % y);
}

int lcm(int a, int b){
    return a * b / gcd(a, b);
}

int main(){
    int n;
    cin >> n;
    vi p(n);
    Srep(n) cin >> p[i];
    int64_t LCM = p[0];
    Srep(n) LCM = lcm(LCM,p[i]);
    Srep(LCM){
        
    }
}