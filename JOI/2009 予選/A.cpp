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
    vi a(4),A(4),b(4),B(4),c(4),C(4);
    Srep(3) cin >> a[i];
    Srep(3) cin >> A[i];
    Srep(3) cin >> b[i];
    Srep(3) cin >> B[i];
    Srep(3) cin >> c[i];
    Srep(3) cin >> C[i];
    a[3] += a[0] * 3600;
    a[3] += a[1] * 60;
    a[3] += a[2];
    A[3] += A[0] * 3600;
    A[3] += A[1] * 60;
    A[3] += A[2];
    b[3] += b[0] * 3600;
    b[3] += b[1] * 60;
    b[3] += b[2];
    B[3] += B[0] * 3600;
    B[3] += B[1] * 60;
    B[3] += B[2];
    c[3] += c[0] * 3600;
    c[3] += c[1] * 60;
    c[3] += c[2];
    C[3] += C[0] * 3600;
    C[3] += C[1] * 60;
    C[3] += C[2];
    vi ansA(3), ansB(3), ansC(3);
    ansA[3] = A[3] - a[3];
    ansB[3] = B[3] - b[3];
    ansC[3] = C[3] - c[3];
    while (ansA[3] >= 3600){
        ansA[3] -= 3600;
        ansA[0]++;
    }
    while (ansA[3] >= 60){
        ansA[3] -= 60;
        ansA[1]++;
    }
    ansA[2] = ansA[3];
    while (ansB[3] >= 3600){
        ansB[3] -= 3600;
        ansB[0]++;
    }
    while (ansB[3] >= 60){
        ansB[3] -= 60;
        ansB[1]++;
    }
    ansB[2] = ansB[3];
    while (ansC[3] >= 3600){
        ansC[3] -= 3600;
        ansC[0]++;
    }
    while (ansC[3] >= 60){
        ansC[3] -= 60;
        ansC[1]++;
    }
    ansC[2] = ansC[3];
    cout << ansA[0] << " " << ansA[1] << " " << ansA[2] << endl;
    cout << ansB[0] << " " << ansB[1] << " " << ansB[2] << endl;
    cout << ansC[0] << " " << ansC[1] << " " << ansC[2] << endl;
}