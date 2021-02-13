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

int main(){
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    Srep(2) Lrep(j,0,2) Lrep(k,0,2) Lrep(l,0,2){
        bool A=0,B=0,C=0,D=0;
        if(i == 1) A = 1;
        if(j == 1) B = 1;
        if(k == 1) C = 1;
        if(l == 1) D = 1;
        int left=0,right=0;
        if(A) left += a;
        else right += a;
        if(B) left += b;
        else right += b;
        if(C) left += c;
        else right += c;
        if(D) left += d;
        else right += d;
        if(left == right){
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
}