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

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0, c = 0;
    Srep(n){
        if(s[i] == 'J') a++;
        if(s[i] == 'O') b++;
        if(s[i] == 'I') c++;
    }
    string ans = "";
    Srep(a) ans += 'J';
    Srep(b) ans += 'O';
    Srep(c) ans += 'I';
    cout << ans << endl;
}