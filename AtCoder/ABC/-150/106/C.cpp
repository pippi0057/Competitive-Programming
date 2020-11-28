#include<stdio.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<bitset>
#include<set>
 
#define Vsort(a) sort(a.begin(), a.end())
#define Vreverse(a) reverse(a.begin(), a.end())
#define Srep(n) for(int64_t i = 0; i < (n); i++)
#define Lrep(i,a,n) for(int i = (a); i < (n); i++)
#define Brep(n) for(int bit = 0; bit < (1<<n); bit++)
#define rep2nd(n,m) Srep(n) Lrep(j,0,m)
#define vi vector<int>
#define vi64 vector<int64_t>
#define vvi vector<vector<int>>
#define vvi64 vector<vector<int64_t>>
#define vc vector<char>
#define vvc vector<vc>
 
using namespace std;

int main(){
    char ans;
    string s;
    int64_t k;
    bool a = 1;
    cin >> s >> k;
    Srep(min(int64_t(s.size()), k)){
        if(s[i] != '1'){
            cout << s[i] << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}