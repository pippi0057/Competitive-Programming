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
#define rep(i,n) for(int i = 0; i < (n); i++)
#define Srep(i,a,n) for(int i = (a); i < (n); i++)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>

using namespace std;

int main(){
    string s;
    int zero = 0, one = 0;
    cin >> s;
    int n = s.size();
    vector<char> ZERO(n), ONE(n);
    rep(i,n) ZERO[i] = s.at(i);
    rep(i,n) ONE[i] = s.at(i);
    if(ZERO[0] == '1'){
        ZERO[0] = '0';
        zero++;
    }
    if(ONE[0] == '0'){
        ONE[0] = '1';
        one++;
    }
    Srep(i,1,n){
        if(ZERO[i-1] == ZERO[i]) {
            ZERO[i-1] == '0' ? ZERO[i] = '1' : ZERO[i] = '0';
            zero++;
        }
        if(ONE[i-1] == ONE[i]) {
            ONE[i-1] == '0' ? ONE[i] = '1' : ONE[i] = '0';
            one++;
        }
    }
    zero < one ? cout << zero << endl : cout << one << endl;
}