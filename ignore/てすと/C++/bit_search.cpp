#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<set>
#include<queue>
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

namespace BS{
    vi ITV(int bit, int n){
        vi S;
        Srep(n) if(bit & (1<<i)) S.push_back(i);
        return S;
    }
}

int main() {
    int n;
    cin >> n;
    Brep(n){
        vi s = BS::ITV(bit,n);
        for(int i : s) cout << i;
        cout << endl;
    }
}