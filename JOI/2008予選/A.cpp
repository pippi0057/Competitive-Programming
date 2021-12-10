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
#define rep2nd(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>

using namespace std;

int main(){
    int ans = 0;
    int input,n=0;
    cin >> input;
    n = 1000 - input;
    while (n >= 500){
        n -= 500;
        ans++;
    }
    while (n >= 100){
        n -= 100;
        ans++;
    }
    while (n >= 50){
        n -= 50;
        ans++;
    }
    while (n >= 10){
        n -= 10;
        ans++;
    }
    while (n >= 5){
        n -= 5;
        ans++;
    }
    while (n >= 1){
        n -= 1;
        ans++;
    }
    cout << ans << endl;
}