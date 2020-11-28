#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>

#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.bigin(), a.end())
#define Srep(n) for(int i = 0; i < (n); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++) 
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vi>
#define vvi64 vector<vi64>

using namespace std;

int main(){
    int a, b, n, s, f;
    bool judge = false;
    cin >> a >> b >> n;
    vi S(1001);
    Srep(1001) S[i] = 0;
    Srep(n){
        cin >> s >> f;
        Lrep(j,s,f+1) S[j] = 1;
    }
    Lrep(i,a,b) if(S[i] == 1) judge = true;
    Lrep(i,a,b){
        int c = 0;
        if(S[i] == 1) c++;
        if(c == 1) judge = false;
    }
    judge ? cout << 1 << endl : cout << 0 << endl;
}