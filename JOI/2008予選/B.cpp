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
    int joi=0,ioi=0;
    string s;
    cin >> s;
    Lrep(i,2,s.size()){
        if((s[i-2] == 'J')&&(s[i-1] == 'O')&&(s[i] == 'I')) joi++;
        if((s[i-2] == 'I')&&(s[i-1] == 'O')&&(s[i] == 'I')) ioi++;
    }
    cout << joi << endl << ioi << endl;
}